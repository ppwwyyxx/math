
### definition

arrival rate $\lambda = 3 $ jobs / sec
server speed = $1/\mu$ sec / job
average service rate = $\mu$ jobs / sec
average service time $ E[T] $

###Q1 Scaling

suppose $\lambda $ turns to $2\lambda $
what change to $\mu$ keeps $E[T]$ ?
+ $\mu \rightarrow 2\mu$
+ $\star$ $\mu \rightarrow < 2\mu$
+ $\mu \rightarrow > 2\mu$

Compare the system:
$\lambda $ jobs / sec + $\mu$ jobs / sec
$2\lambda $ jobs / sec + $2\mu$ jobs / sec == $\lambda $ jobs / halfsec + $\mu$ jobs / halfsec
So, $E[T]$seconds -> $E[T] $ halfseconds

__The definition of second can change to any unit__


$\lambda = 9 $ jobs / sec
One queue has 12 servers behind it with each $\mu=1$
server serves with "grab job when free" strategy.

when $\lambda \rightarrow 9Million$, what keeps $E[T]$ ?
Answer is $9.003 Million$. $3000^2 / 9m == 3^2 / 9$

__Square root staffing law__


### Q2 Dispatching
A lot of identical servers in the backend, find a policy to choose which queue to dispatch a job, to minimize average response time.
+ random choose
+ JSQ (join shortest queue: with least #jobs)
+ round-robin (go in cyclic)
+ $\star$ LWL (least work left: sum the job sizes in each queue)
+ $\star$ SITA (size interval task assignment, use different lane for different size)

__in supermarket, there is a express lane!!__

In average, RR better than random, in the sense that: arrival separation in each queue is more even.
LWL is better than JSQ, certainly, but requires knowledge.
LWL is equivalent to "one queue with multiple backend" model, but requires extra knowledge.

LWL usually is worse than SITA. but sometimes (3/2 moments! of size) not.
How to perform SITA? not well understood
How to ensure some kind of fairness? (in terms of queueing time, first come, etc.)


#### Fast-Slow backend
Two server, one with $\mu$, one with $2\mu$. no knowledge about job size.
How to choose which server to dispatch?

Consider JSQ, two queue with $n_1$ jobs and $n_2$ jobs.
Do we choose $min(n_1, n_2/2)$ or $min(n_1, n_2)$ (JSQ).
JSQ might just do the right thing automatically.

When we don't know about job number, if we have to select a probability to send to the two queue, what is the number?
if $\lambda$ very small, always choose the faster one.
if $\lambda$ very large, choose $1/3, 2/3$.


#### Order of job serve
No knnowledge of job size.
FCFS(first come first serve), LCFS, Random choose

The average response time $E[T]$ is actually the same !
The variance is not.

A variant: Preemptive-LCFS. pause the current job and always work on the "last come job" as soon as it arrives.
If job switch is free, it is actually better!!! Job switch will be more likely to expose you to small jobs!!

variants on P-LCFS: maximum working time on one job to switch.


### Throughput and Utilization

#### definition
$S$ = job size
$T$ = resposne time
$T_a$ queueting = T - S
$N$: #jobs in system
$N_a$ : #jobs in queue

Throughput $X$ = rate of completion
Utilization (load) $\rho$ = fraction of time server is busy

For queue with $\lambda < \mu$,
$\rho = \frac{\lambda}{\mu}, X = \lambda$

$C(t)$ = #completions by time t
$B(t)$ = total busy time in $[0, t]$
Then $X = \lim \frac{C(t)}{t}, \rho = \lim \frac{B(t)}{t} $
$E[S] = \lim \frac{B(t)}{C(t)}, X = \mu\rho$

__Open System__: arrivals are exogenous, doesn't depend on anything in the system
__Close System__: arrivals can be triggered by job completion

__Closed Interactive System__:
Small Web System: everyone works -> submit stuff -> wait result -> works -> submit stuff -> loop
The response triggers the next arrival.
Only when #user is very large, it becomes more open.
When work time is small, becomes closed batch system.

__Closed Batch System__:
Have a large number of jobs, only $N$ is allowed to run simutaneously.
Have them run, send new job as soon as some completes.
$X = \mu$ (always busy!).

In closed system, change policy in queue (such as short job first rather than FCFS) doesn't help. (2007 paper). In open system is always better.

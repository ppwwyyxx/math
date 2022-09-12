### Convergence of Sequence of RV
#### 1. almost sure convergence (convergence with prob 1)
$Y_n \xrightarrow{a.s.} \mu, $ as $  n\to \infty$:
$Pr\{\lim _{n\to\infty} Y_n=\mu\}=1$
fraction of sample paths, where the value of RV converges to $\mu$, is 1

Think of $X_n = 0, 1 $ with prob 0.5 each, $Y_n=\sum X_n / n$
number of sample paths of $Y_n$ not convergence to 0.5, is uncountable infinity:
Proof: build any binary sequence combination of 001 and 101

#### 2. convergence in probability
$Y_n\xrightarrow{P}\mu$, as $n\to \infty$:
$\forall \epsilon >0, \lim_{n\to\infty}Pr\{|Y_n-\mu|>\epsilon\}=0$
for particular n, fraction of sample paths of length $ n$ within the good range ($\epsilon$ distance to $\mu$) tends to 1, as $n\to\infty$ .

1 $\rightarrow $2, but not otherwise.
AntiExample:
fraction of 'good for now' sample paths tends to 0, but no sample path is really good. (e.g., each path has less frequent spikes over time)

## Law of Large Numbers
$X_i$ iid, $Y_n = \sum X_i  / n$
+ $Y_n \xrightarrow{P} E[X]$ (WLLN)
+ $Y_n \xrightarrow{a.s.} E[X]$ (SLLN)

## Time Avg vs Ensemble Avg
$N(v)$ = #jobs at time v. what is average # jobs?

Time Avg: $\overline{N} =\lim_t \frac{\int_0^t N(v)dv}{t} $
it takes average on one sample path, over time
Actually it is: $\overline{N}(w) = \lim_t \frac{\int_0^t N(v, w)dv}{t} $

Ensemble Avg:  Average result at time T between all sample paths.
$\overline{N} = \lim_t E_w[N(t, w)]$
Average of results among paths might not exists! , e.g.: periodic

### Theorem
Given __ergodic__ system, $\overline{N}_{ensemble}$ exists, $\overline{N}_{time} = \overline{N}_{ensemble}$ with prob 1 (for almost all sample path).
Ergodic: 常返，非周期. (Positive Recurrent + Irreducible + Aperiodic)
Positive Recurrent: 在有限时间内返回状态
Irreducible: 每个状态都能到达别的状态


### Little's Law:
$E[N]$: mean # jobs in system (ensemble)
$E[T]$: mean time in system

For any open system, s.t. $\lambda = X, \overline{N}_{time}=\lambda \overline{T}_{time}$
$\Rightarrow$ For any ergodic open system， $E[T] = \frac{E[N]}{\lambda}$

__Beautiful proof__ is on notes!

For a single queue, think of Little's Law on Serving!
$\overline{N}=\rho,$ (fraction of time server is busy)
$\overline{T}=E[S]$, (expected time of serving)
$\Rightarrow \rho = \lambda / \mu$

In closed system, $N$ is fixed (in either batch closed or interactive closed).
$N = X E[T]$, $T$ is average time for whole loop (running + thinking for interactive closed system)

For any single device, little's law holds.

#### Bottleneck's Law
For a single device, $\rho_i = X E[D_i] = X E[S_i]E[V_i] = X_i E[S_i]$
$V_i$ is number of visit on this device for a job.
$D_i$ is the demanded total time of this device for each job.

### well-approximate a closed system:
For ANY interactive closed system, $N$ users and $m$ devices:
Let $D_{max} = max E[D_i], D = \sum_{i=1}^mD_i$
Then $X\le min \left\{ \frac{N}{D+E[Z]}, \frac{1}{D_{max}}\right\},
E[R] \ge max\left\{ D, ND_{max}-E[Z]\right\}$
First item in each is low $N$ asymptote, second is for high $N$.
Proof:
For high $N$, bottleneck $\rho \le 1$ is tight, therefore $X\le \frac{1}{D_{max}}$, the other part is trival.
For low $N$, queueing time $\approx 0 \Rightarrow E[R]\ge D$ is tight, the rest is trival.

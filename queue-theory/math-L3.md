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
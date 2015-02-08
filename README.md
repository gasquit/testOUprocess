The idea is to simulate OU process given parameter set {k, sigma} and test a pair trade strategy on the paths, which is defined by up/down + open/close threshold. 

Essentially I want to study two things:

1. Given a parameter set {k, sigma}, what's the best threshold level? How does the PnL change as the threshold changes? Does that actually make a big difference?

2. From the perspective of applying the best strats (optimal threshold), how does optimal pnl change to varying {k, sigma}. Do these two values have to satisfy certain condition should we consider a mean-reversion strategy. (Intuitively this is true, for in the extreme case when k is very small in relation to sigma, this process is essentially random walk, and thus no signal to exploit)



A couple things to think through:

a. how do you evaluate strategy performance? Especially in the case of MR, the common metrics like Sharpe doesn't quite make sense, because returns aren't really independent in nature because of the mean reversion, and there are periods of no activity at all.

Common senses would suggest the following: average holding period,total holding period, average mean reverting period (both in # of days), # of MR in given time frame (# signal appearance), total pnl, pnl series (MtM). 


b. Code design: what are the modules?

Thinking in C++, path evolve, RN gen, strategy simulation and results collection, top level optimal strat search, compare OU param impact.

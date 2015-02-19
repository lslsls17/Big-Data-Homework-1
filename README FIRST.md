# BDiF2015-Haotian-Wu

Read Me:
How to Run? (Capital Letter for SCRUB and NORMAL):
1) $make
2) $./main SCRUB [data name]
3) $./main NORMAL

Sample Output:
make
./main SCRUB [data name]
SCRUBING
2015-02-18 23:41:06,913 [INFO] Calibrating the standard for noise using time : 0.0575
2015-02-18 23:41:08,719 [INFO] Scrub data to signal.txt and noise.txt takes : 11.7025
2015-02-18 23:41:08,724 [INFO] signal percentage : 99.227
./main NORMAL
TEST NORMALING
2015-02-18 23:41:08,871 [INFO] Test Normal, JB=6383.1, Chi-Square from Normal Dist=5.99 within 5 percent confidence level
2015-02-18 23:41:08,877 [WARN] The sample are not normal within 5 percent confidence level by Jarque Bera Test
2015-02-18 23:41:08,877 [INFO] Test Normal takes : 0.69099
2015-02-18 23:41:09,022 [INFO] Test Log Normal, JB=1055.76, Chi-Square from Normal Dist=5.99 within 5 percent confidence level
2015-02-18 23:41:09,022 [WARN] The sample are not log normal within 5 percent confidence level by Jarque Bera Test
2015-02-18 23:41:09,022 [INFO] Test Log Normal takes : 0.69481
2015-02-18 23:41:09,022 [INFO] Sample is more like log normal than normal 

Tools Used:
STL
Log4CPP
thread
boost
(try to use MPI, but failed to link from makefile)

Idea:
1) Use sample data (data10k.txt) to calibrate the range of usual price, by calculation its sample mean and standard deviation. Claim that if mean +- 3* standard deviation will be unlikely to be normal price
2) Read big data line by line. In this way, there is no memory concern. (However, because I used getline initially, it is not fitable to use multi-thread computing for reading data)
     Write to signal.txt and noise.txt based on noise calibration and negtive volume. Also pass the total number of data in a temp file
3) Using Jarque-Bera Test for calculation the kurtosis and skewness from signal.txt to check normality or log-normal distribution. 
     Using multithread calculation for testing normal, and single thread for test log normal (multithread is slightly quicker)
http://en.wikipedia.org/wiki/Jarque%E2%80%93Bera_test

Write at last:
It is a really nice practice. I did not have time to fulfill all my thought and modify my wrong path. The last two weeks are really intensive (IAQF, interviews and homeworks). I hope to get started earlier with next assignment and do better.

Chengbin gives me a lot of help. Many thanks to Chengbin
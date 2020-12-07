# 326-project4
//the length and/or size of the taskList array may need to be changed for larger data sets

//for fcfs
make fcfs
./fcfs schedule.txt
./fcfs pri-schedule.txt
./fcfs rr-schedule.txt

//for priority
make priority
./priority schedule.txt
./priority pri-schedule.txt
./priority rr-schedule.txt


//for round robin
make rr 
./rr schedule.txt
./rr pri-schedule.txt
./rr rr-schedule.txt

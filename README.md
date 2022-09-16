# C program to schedule list of process using shortes job first schedulling method

### Inputs
*Number of processes
-Process IDs
-Process Arival Times
-Process brust times

### Outputs
-Process ID, Arival Time, Brust Time, End Time, Wait Time, Turn Around Time according to Round Robin with 3 quantum
-Process ID, Arival Time, Brust Time, End Time, Wait Time, Turn Around Time according to Round Robin with 6 quantum
-Process ID, Arival Time, Brust Time, End Time, Wait Time, Turn Around Time according to Shortest job first


## Explainatioin of Variables
-p = Process ID
-at = Arival Time
-bt = Brust Time
-nbt = Variable brust time used in Round Robin
-et = End Time
-Pro[] = Sturucture Array storing all Process variables
-wl[] = Wait list storing sequence of Process execution
-tq = Time quantum of Round Robin


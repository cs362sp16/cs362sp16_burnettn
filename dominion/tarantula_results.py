from __future__ import division

fo = open("results.txt", "r");

passes = [0] * 16
fails = [0] * 16

num_passed = 0
num_failed = 0
result = fo.read(1);
i = 0

#for i in range(0, 100):
while(result == "1" or result == "0"):
    if(result == "1"):
        num_passed += 1
    else:
        num_failed += 1
    #print "\n\n--------------------\n TEST: ", i, "\n-----------------"
    #get the 1 or 0 to see if the test passed or failed
    #result = fo.read(1);
    #print "Pass or fail: ", result
    #read until the end of the line
    for index in range(0, 15):
        hide = fo.read(4)
        check_read = fo.read(1)
        if(check_read != '#'): #If the line is covered
            if(result == "1"):
                passes[index] += 1;
            else:
                fails[index] += 1;
        string = fo.readline()
        #if(check_read != '#'):
        #    if(result == "1"):
        #        print string, " PASSED"
        #    else:
        #        print string, " FAILED"
        #print string
    result = fo.read(1);
    i += 1
#print passes
#print fails

print "passed: ", num_passed
print "failed: ", num_failed

#for number in range(649, 664):
#    print number, " Passes: ", passes[number-649], ", Fails: ", fails[number-649]

for number in range(649, 664):
    suspiciousness = ((fails[number-649] / num_failed)/ 
            ((passes[number-649] / num_passed) + (fails[number-649] / num_failed)))
    print "Line ", number, ": ", suspiciousness

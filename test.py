import numpy as np
f = open('testdo','w+')
f.write('taskinit 46000\n')
comd = []
for i in range(26):
    for j in range(26):
        for k in range(26):
            #for l in range(26):
            #comd.append('tasknew -n '+chr(ord('a')+i)+chr(ord('a')+j)+chr(ord('a')+k)+chr(ord('a')+l)+' '+str(l+k*26+j*26*26+i*26*26*26) +'\n')
            comd.append('tasknew -n '+chr(ord('a')+i)+chr(ord('a')+j)+chr(ord('a')+k)+' '+str(k+j*26+i*26*26) +'\n')
comda =  np.array(comd)
del comd
np.random.shuffle(comda)
for i in range(len(comda)):
    f.write(comda[i])
f.write('taskremove -r 1000\n')
f.write('taskq -he\n')
f.write('usage\n')
f.write('q -f\n')
f.close()

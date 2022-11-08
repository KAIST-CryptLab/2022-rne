import os, random

def test(m, n, k, r, t, g): 
    with open('test_gd_temp.txt', 'w') as file:
        file.write(str(m)+'\n'+str(n)+'\n'+str(k)+'\n'+str(r)+'\n'+str(t)+'\n')
    os.system('cat test_gd_temp.txt | python random_testcase.py')
    os.system('./guess_determine.sh '+str(g)+'\n')
    name = str(m)+'_'+str(n)+'_'+str(k)+'_'+str(r)+'_'+str(t)+'_'+str(g)+'_'+str(random.random())+'_'
    os.system('mv guess_determine_result.txt ./test_gd_result/'+name+'rs')
    os.system('mv testcase.txt ./test_gd_result/'+name+'tc')

test(12, 64, 10, 3, 4, 1)
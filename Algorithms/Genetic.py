def decToBin(x):
    return bin(x)[2:]

def binToDec(b):
    b = b[::-1]
    sum = 0
    for i in range(len(b)):
        sum += int(b[i])*(2**i)
    return sum       

def binform(l):
    m = 0
    x = 0
    a = []
    for x in l:
        if m<len(decToBin(x)):
            m = len(decToBin(x))
    for i in range(len(l)):
        if m>len(decToBin(l[i])):
            x = "0"*(m-len(decToBin(l[i]))) + decToBin(l[i])
            a.append(x)
        else:
            a.append(decToBin(l[i]))
    return a

def actual(x):
    if x>=float(str(x).split('.')[0]+".5"):
        return int(str(x).split('.')[0])+1
    else:
        return int(str(x).split('.')[0])

def genetic(f,ran,nos):
    for i in nos:
        if i<ran[0] or i>ran[1]:
            return f"Select numbers in range{ran}"
    pop_size = len(nos)
    bin_nos = binform(nos)
    k = 0
    fx = []
    prob = []
    exp = []
    cross_list = []
    for i in nos:
        x = i
        fx.append(eval(f))
    for i in fx:
        prob.append(float("%.3f"%(i/sum(fx))))
        exp.append(float("%.3f"%(i/(sum(fx)/len(fx)))))
    print("sr.no\tinit_pop\tx\tf(x)\tprob_count\texp_count\tactual_ct\n")
    for i in range(len(nos)):
        print(f"{k}\t{bin_nos[k]}\t\t{nos[k]}\t{fx[k]}\t{prob[k]}\t\t{exp[k]}\t\t{actual(exp[k])}")
        if actual(exp[k])>=1:
            cross_list.append((nos[k],bin_nos[k],actual(exp[k])))
        k += 1
   
    m = 0
    for i in range(len(cross_list)):
        if cross_list[i][2]>m:
            max = cross_list[i]
            m = cross_list[i][2]
            
    cross = [i for i in cross_list if i!=max]
    print("\nsr.no\tpop\tcrossover\tx\tf(x)\n")
    for i in range(len(cross)):
        a = max[1][:len(max[1])//2+1] + cross[i][1][len(max[1])//2+1:]
        b = cross[i][1][:len(max[1])//2+1] + max[1][len(max[1])//2+1:]
        x = binToDec(a)
        print(f"{i+1}\t{max[1]}\t{a}\t\t{x}\t{eval(f)}")
        x = binToDec(b)
        print(f"  \t{cross[i][1]}\t{b}\t\t{x}\t{eval(f)}\n")
        
  
    
if __name__=="__main__":
    f = "x**2-x"
    ran = (0,31)
    random_no = [23,13,9,28]
    genetic(f,ran,random_no)
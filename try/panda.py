a = "abcd"#input
def power(a):
    l = []
    for i in range(len(a)+1):
        for j in range(i):
            s =a[j:i]
            l.append(s)
    l = set(l)
    return(l)

l = ['z', 'c', 'b']#input
s = []
for i in l:
    if i in power(a):
        s.append(i)
print(sorted(s))
//用数组b来记录这个最长的子序列
//a是输入的序列
b[1]=a[1]; 
len =1;
    for (i=2;i<=n;++i)
    {
        if (a[i]>=b[len])   //如果a[i]大于b的末尾元素直接在b后面加上a[i]
            b[++len]=a[i];
        else
        {
            t=upper_bound( b+1 , b+len+1 , a[i] )-b; //寻找b数组中第一个大于a[i]的下标
            b[t]=a[i];
        }
    }
//最后len的长度即为最长的子序列长度
Java判断⼀个回⽂串

1.如果回⽂串是⼀个纯数字的数：

```java
public static void main(String[] args) {
	System.out.println(isHuiWen(3245423));
}
private static boolean isHuiWen(int target) {
    int temp=target;
    int j=0;
    while(temp!=0)
    {
        j=j*10+temp%10;
        temp=temp/10;
    }
    if(j==target){
        return true;
    }else{
        return false;
    }
}
```

2.如果回⽂串是⼀个字符串最简单的实现⽅法就是：

将原字符串反转，将反转后的字符串和原字符串对⽐，如果相同则为回⽂，否则不是。代码实现如下：

```java
public static void main(String[] args) {
    System.out.println(isHuiWen("abababa"));
}

private static boolean isHuiWen(String string) {
    StringBuilder stringBuilder = new StringBuilder(string).reverse();
    String newString = new String(stringBuilder);
    if (newString.equals(newString)) {
        return true;
    } else {
        return false;
    }
}
```

还有⼀种⽅法：就是将原字符串的⼦区间对⽐，第i个字符和第length()-1-i个字符如果全部相等，则为回⽂，否则不是。

```java
public static void main(String[] args) {
    System.out.println(isHuiWen("sbcdcbs"));
}

private static boolean isHuiWen(String target) {
    int count = 0;
    for (int i = 0; i < target.length() / 2; i++) {
        if (target.substring(i, i + 1).equals(target.substring(target.length() - 1 - i, target.length() - i))) {
            count++;
        } else {
            break;
        }
    }
    if (count == target.length() / 2) {
        return true;
    } else {
        return false;
    }
}
```


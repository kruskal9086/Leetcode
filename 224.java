class Solution {
    int i = 0;
    public int calculate(String s) {
        int sum = 0;
        int sign = 1;
        while(i < s.length()){
            int c = s.charAt(i);
            i++;
            if(c == '('){
                sum += sign * calculate(s);
            } else if(c == ')'){
                break;
            } else if(c == '-'){
                sign = -1;
            } else if(c == '+'){
                sign = 1;
            } else if(Character.isDigit(c)){
                int num = c-'0';
                while(i<s.length() && Character.isDigit(s.charAt(i))){
                    num = 10*num+s.charAt(i++)-'0';
                }
                sum += sign * num;
            }
        }
        return sum;
    }
}
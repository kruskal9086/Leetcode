class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        if n == 0:
            return False
        
        i = 0
        count_num = 0
        count_point = 0
        while i < n and s[i] == ' ':
            i += 1
        
        if i < n and (s[i] == '+' or s[i] == '-'):
            i += 1
        
        while i < n and (s[i].isdigit() or s[i] == '.'):
            if s[i] == '.':
                count_point += 1
            else:
                count_num += 1
            i += 1
        
        if count_point > 1 or count_num < 1:
            return False
        
        if i < n and (s[i] == 'e' or s[i] == 'E'):
            i += 1
            count_num = 0
            count_point = 0
            if i < n and (s[i] == '+' or s[i] == '-'):
                i += 1
            
            while i < n and (s[i].isdigit() or s[i] == '.'):
                if s[i] == '.':
                    count_point += 1
                else:
                    count_num += 1
                i += 1
            
            if count_point > 0 or count_num < 1:
                return False
        
        while i < n and s[i] == ' ':
            i += 1
        
        return i == n
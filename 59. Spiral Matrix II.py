class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        answer = [[-1] * n for _ in range(n)]
        left, up, right, down = 0, 0, n-1, n-1
        number = 1
        while left < right:
            
            temp = left
            while temp < right:
                answer[up][temp] = number
                temp += 1
                number += 1
            
            temp = up
            while temp < down:
                answer[temp][right] = number
                temp += 1
                number += 1
                
            temp = right
            while temp > left:
                answer[down][temp] = number
                temp -= 1
                number += 1
                
            temp = down
            while temp > up:
                answer[temp][left] = number
                temp -= 1
                number += 1
                
            left += 1
            up += 1
            
            right -= 1
            down -= 1
            
        if n % 2 != 0:
            answer[n // 2][n // 2] = number
        
        return answer
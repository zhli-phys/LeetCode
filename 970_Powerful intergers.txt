class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        xmax = 0 if x == 1 else math.floor(math.log(bound, x)) 
        ymax = 0 if y == 1 else math.floor(math.log(bound, y))
        ans = set()
        for i in range(xmax + 1):
            si = pow(x, i)
            for j in range(ymax + 1):
                s = si + pow(y, j)
                if s <= bound:
                    ans.add(s)
                else:
                    break
        return list(ans)
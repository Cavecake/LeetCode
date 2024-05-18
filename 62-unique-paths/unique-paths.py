class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        MEM = [[1 for y in range(m)] for x in range(m+n)]
        indexLast = 0
        for x in range(m+n - 1):
            for y in range(1,min(x,m)):
                MEM[(indexLast + 1)][y] = MEM[indexLast][y-1] + MEM[indexLast][y]
            #indexLast = (indexLast + 1) % 2
            indexLast = x
        print(MEM)
        return MEM[indexLast][m -1]
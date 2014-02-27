#!/usr/bin/python
# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    epsilon = 10000
    def minus_p(self,p1,p2): return (p2[0] - p1[0], p2[1] - p1[1])
    def divid(self,p): return self.epsilon*p[1]/p[0]
    def maxPoints(self, points):
        if len(points) == 0:
            return 0
        dictg = {}
        mask = []
        maxpts = []
        pts_len = len(points)
        matrix =  [points]*pts_len
        mask = [[row[i] for row in matrix] for i in range(pts_len)]
        diff_mat = []
#        print mask
        for i in range(0,pts_len):
            diff_mat.append(map(self.minus_p,mask[i],points))
        print diff_mat
        for i in range(1,pts_len):
            dictg.clear()
            maxpt = 0
            mat1 = diff_mat[i-1][i:]
            mat1.sort()
            dups = mat1.count((0,0))
            grads = map(self.divid,mat1[dups:])
            for j in range(0,len(grads)):
                key = str(grads[j])
                if key not in dictg:
                    dictg[key] = 0
                dictg[key]+=1
            for key in dictg:
                if maxpt < dictg[key]: maxpt = dictg[key]
            maxpts.append(maxpt+dups+1)
        ans = 0
        for i in maxpts:
            if ans < i: ans = i
        return ans

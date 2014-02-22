class Solution:
    # @param tokens, a list of string
    # @return an  eger
    def evalRPN(self, tokens):
        if len(tokens) == 0:
            return
        vec = []
        ops = ('+','-','*','/')
        for i in range(len(tokens)):
            if ops.count(tokens[i]):
                rnum = vec.pop()
                lnum = vec.pop()
                if tokens[i] == '+':
                    vec.append( (lnum) +  (rnum))
                elif tokens[i] == '-':
                    vec.append( (lnum) -  (rnum))
                elif tokens[i] == '*':
                    vec.append( (lnum) *  (rnum))
                else :
                    if (lnum > 0 and rnum <0) or (lnum < 0 and rnum > 0):
                        vec.append(int(round(float(lnum) / float(rnum) + 0.5)))
                    else:
                        vec.append(lnum/rnum)
                print "%d %s %d = %d"%(lnum,tokens[i],rnum,vec[-1])
            else:
                vec.append(int(tokens[i]))
        return vec[0]


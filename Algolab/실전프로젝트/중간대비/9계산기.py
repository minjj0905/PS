import sys

def postfix(s):
  prior = {'*':3,'/':3,'+':2,'-':2,'(':1} 
  stack = []
  ans = []
  arr = s.split()

  for a in arr:
    if a.isdigit():
      ans.append(int(a))
    elif a == '(':
      stack.append(a)
    elif a == ')':
      while stack and stack[-1] != '(':
        ans.append(stack.pop())
      stack.pop()
    else:
      while stack and prior[a] <= prior[stack[-1]]:
        ans.append(stack.pop())
      stack.append(a)

  while stack:
    ans.append(stack.pop())
  
  return ans

def calc(arr):
  stack = []

  for a in arr:
    if a == '+':
      stack.append(stack.pop() + stack.pop())
    elif a == '-':
      stack.append(-(stack.pop() - stack.pop()))
    elif a == '*':
      stack.append(stack.pop() * stack.pop())
    else:
      stack.append(a)

  return stack.pop()

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()
    sys.stdout.write(str(calc(postfix(s))) + '\n')
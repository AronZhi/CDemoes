def Hello():
    print("hello python")

def Fib(index):
    if index <= 0:
        return 0
    elif index == 1 or index == 2:
        return 1
    else:
        return Fib(index - 1) + Fib(index - 2)

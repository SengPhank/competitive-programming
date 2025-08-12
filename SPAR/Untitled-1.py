
def func():
    w, h = map(int,input().split())
    w = w/1000
    h = h/1000
    area = w*h
    n = int(input())
    for _ in range(n):
        a, b = map(int,input().split())
        a =a/1000
        b =b/1000

        area -= a*b

    if area <= 0:
        print("Please check the dimensions.")
        return
    
    print(f"The Net Wall Panel Area is {round(area,2):.2f} square metres.")
    return 

func()



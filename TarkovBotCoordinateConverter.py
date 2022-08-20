while 1:
    print("Please input total length:",end='')
    total_length=float(input())
    
    multi=65536/total_length
    total_length=total_length/2
    print("Please input old coordinate:",end='')
    old_coordinate=float(input())
    result=old_coordinate-total_length
    result=result*multi

    print(int(result))
    input()
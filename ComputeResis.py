Res = {"red": 1.8,
       "orange": 1.8,
       "yellow": 1.8,
       "yellow-green": 1.8,
       "green": 3.3,
       "blue": 3.3,
       "white": 3.3,
       "UV": 3.3,
       }
print("*********************************************************************************")
while 1:
    try:
        V = float(input("Power source voltage : "))
        LED = input("For which LED you want to compute the resistance, the available one are :\n>> red\n>> orange\n>> yellow\n>> yellow-green\n>> green\n>> blue\n>> white\n>> UV\n")
        print("The resistance value is : {0}".format((V - Res[LED]) / 25 * 10**3))
        print("*********************************************************************************")
    except:
        pass

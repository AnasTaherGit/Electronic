import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style


def Voltage(x, in_min=0, in_max=1023, out_min=0, out_max=5):

    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


Arduino = serial.Serial('COM7', 9600)
fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)
DATA = []
time = [0.1 * k for k in range(0, 100)]


def animate(interv):
    while (not Arduino.inWaiting()):
        print("waiting data ...")
    print('reading ..')
    data = int(Arduino.readline())
    DATA.append(Voltage(data))
    print('readed')
    print("{0:.2f}".format(Voltage(data)))
    del DATA[0]
    ax1.clear()
    ax1.set_ylim([-6, 6])
    ax1.plot(time, DATA)
    print("plotted")


print("Collecting data ...")

while 1:
    if Arduino.inWaiting():
        data = int(Arduino.readline())
        # print("{0:.2f}".format(Voltage(data)))
        DATA.append(data)
    if len(DATA) == 100:
        DATA = list(map(Voltage, DATA))
        break
    # print(len(DATA))

ani = animation.FuncAnimation(fig, animate, interval=50)
plt.show()

import serial
Arduino = serial.Serial('COM7', 9600)

def Voltage(x, in_min=0, in_max=1023, out_min=0, out_max=5):

    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

while 1:
    if Arduino.inWaiting():
        data = int(Arduino.readline())
        print("{0:.2f}".format(Voltage(data)))

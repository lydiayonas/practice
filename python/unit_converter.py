#Ask user to enter a value of a kilometer
value= float(input("enter the value of kilometer:"))
#Ask user to which unit of measurement to convert
print("To which unit do you want to convert?")
print("1 for kilometer to mile")
print("2 for kilometer to meter")
unit = int(input("enter 1/2: "))
#compute the value to the desired unit
# display the new unit of measurement


if unit == 1:
    print(f"The value is {value * 0.62} miles")
elif unit == 2:
    print(f"The value is {value * 1000} meters")



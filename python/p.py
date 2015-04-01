from tkinter import *
 
form = Tk()

form.title("Tkinter.TK Demo")
form.geometry("300x200+10+10")
#form.iconbitmap('Icon.ico')
form.resizable(False, False)
form.minsize(300, 200)
form.maxsize(600, 400)
#form.attributes("-toolwindow", 1)
form.attributes("-topmost", 1)
#form.state("zoomed")
#form.iconify()
#form.deiconify()
form.configure(background='black')

form.mainloop()

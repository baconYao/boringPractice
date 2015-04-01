from tkinter import *
from tkinter.filedialog import *

if __name__ == '__main__':
    root = Tk()
    root.title("HEllo~")
    # root.fileName = askopenfilename(filetypes = (("allfiles","*"),("text","*.txt")))
    # print(root.fileName)    
    root.fileName = asksaveasfile(defaultextension=".png",filetypes = (("allfiles","*"),("text","*.txt"),("PNG","*.png")))

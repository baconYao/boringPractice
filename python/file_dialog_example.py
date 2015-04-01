from tkinter import *
import tkinter.filedialog 

options = {}
options['filetypes'] = [("allfiles","*"),("text","*.txt")]
options['initialdir'] = "c:\\"
options['multiple'] = True

options['title'] = "tkFileDialog.askopenfilename"
print tkinter.filedialog.askopenfilename(**options) or "Without selected!"

options['title'] = "tkFileDialog.askopenfilenames"
print Tk().tk.splitlist(tkFileDialog.askopenfilenames(**options)) or "Without selected!"

options['title'] = "tkFileDialog.askopenfile"
fs = tkFileDialog.askopenfile(**options) 

if fs:
    print fs.name
else:
    print "Without selected!"

options['title'] = "tkFileDialog.askopenfiles"
files = tkFileDialog.askopenfiles(**options)

print files

if files:
    for fs in files:
        print fs.name
else:
    print "Without selected!"


options['title'] = "tkFileDialog.asksaveasfilename"
options['defaultextension'] = '.txt'
del options['multiple']
print tkFileDialog.asksaveasfilename(**options) 

del options['filetypes']
del options['defaultextension']
options['title'] = "tkFileDialog.asksaveasfile"

print tkFileDialog.asksaveasfile(**options).name

options['title'] = "tkFileDialog.askdirectory"
print tkFileDialog.askdirectory(**options) 

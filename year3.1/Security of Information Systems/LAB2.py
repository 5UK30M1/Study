from tkinter import filedialog
import tkinter as tk
import time
from tkinter import *
from pathlib import Path
from enum import Enum
import Pmw

lang_en = True

class EntryFormatting:
        def __init__(self, master):
            frame = Frame(master)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            self._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='Phone Number:\n(nnn)-nnn-nnn',
                format=self.fmtPhone, enter=self.activate)
            self._crdprt = self.createField(frame, width=11, row=1, col=2,
                label='SSN#:', format=self.fmtSSN,
                enter=self.activate)
            frame.pack(side=TOP, padx=15, pady=15)

        def createField(self, master, label='', text='', width=1,
            format=None, enter=None, row=0, col=0):
            Label(master, text=label).grid(row=row, column=col-1,
                 padx=15, sticky=W)
            id = Entry(master, text=text, width=width, takefocus=1)
            id.bind('<KeyRelease>', format)
            id.bind('<Return>', enter)
            id.grid(row=row, column=col, pady=10, sticky=W)
            return id

        def activate(self, event):
            print ('<Return>: value is', event.widget.get())

        def fmtSSN(self, event):
            current = event.widget.get()
            if len(current) in [3, 6]:
                current = '%s-' % current
            event.widget.delete(0, END)
            event.widget.insert(0, current)
            root = Tk()

class pflile:
    workfile = 0
    translated = ""
    origtext = ""
    key = -2000
    text = 0
    key_type = 0
    A = 0
    B = 0
    C = 0
    var = BooleanVar
    String = ""
    input_type = 0
    #alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ1234567890,.;!?"
    #alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890,.;!?"
    alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
    alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alphabet = ""

    def __init__(self):
        self.var = BooleanVar()
        self.var.set(True)
        self.text = Text(root)
        self.text.pack()
        scroll = Scrollbar(root, command=self.text.yview)
        self.text.configure(yscrollcommand=scroll.set)
        if(self.var.get() == True):
            self.alphabet = self.alphabet_EN
        else:
            self.alphabet = self.alphabet_UA

    def reinit(self):
        self.text = Text(root)
        self.text.pack()
        scroll = Scrollbar(root, command=self.text.yview)
        self.text.configure(yscrollcommand=scroll.set)
        if(self.var.get() == True):
            self.alphabet = self.alphabet_EN
        else:
            self.alphabet = self.alphabet_UA

    def about(self):
        w = Tk()
        w.title('About')
        L = Label(w, text="About tk\n\n Version 0.01\nCopyright Novak M.S. TR-61\nAll Rights Reserved")
        L.pack()

    def newf(self):
        self.text.pack()
        if(self.workfile == 0):
            self.savefas()

    def closef(self):
        self.text.destroy()
        self.workfile = 0
        self.translated = ""
        self.key = 1
        self.text = 0
        self.alphabet_UA = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
        self.alphabet_EN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        self.reinit()

    def openf(self):
        root.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                   filetypes=(("txt files", "*.txt"), ("all files", "*.*")))
        self.workfile = Path(root.filename)
        self.text.insert(END,self.workfile.read_text())
        self.origtext = self.workfile.read_text()
        self.text.pack()

    def savef(self):
        self.workfile.write_text(self.text.get("end-1c linestart", "end"))

    def savefas(self):
        root.filename = filedialog.asksaveasfilename(initialdir="/", title="Select file",
                                                     filetypes=(("txt files", "*.txt"), ("all files", "*.*")))

        workfile = Path(root.filename)
        workfile.write_text(self.text.get("end-1c linestart", "end"))

    def valueChanged(self):
        #print('Current value = %s' % ['Off', 'On'][self.var.get()])
        print('1')
        if(self.var.get() == True):
            self.alphabet = self.alphabet_EN
        else:
            self.alphabet = self.alphabet_UA

    def crypting(self, crypt):
        self.key %= len(self.alphabet)
        ind = 0
        s_ind = 0
        for symbol in self.origtext:
            low_sybol = False
            if(symbol.islower()):
                symbol = symbol.upper()
                low_sybol = True
            num = self.alphabet.find(symbol)
            if(self.alphabet.find(symbol) >= 0):
                if(self.key_type == 0): step_key = self.key + ind
                elif(self.key_type == 1): step_key = self.A * ind + self.B
                elif(self.key_type == 2):
                    step_key = self.A * ind * ind + self.B *ind + self.C
                elif(self.key_type ==3):
                    if (s_ind >= len(self.String)):
                        s_ind %= len(self.String)
                    #step_key = ord(self.String[s_ind])
                    step_key = ord(self.alphabet
                                   [self.alphabet.find(self.String[s_ind])])
                if(crypt==1):num += step_key
                else:num -= step_key
                if(num >= len(self.alphabet) or num < 0):
                    num %= len(self.alphabet)
                symbol = self.alphabet[num]
            if(low_sybol):
                symbol = symbol.lower()
                low_sybol = False
            self.translated += symbol
            ++ind
            ++s_ind
        print(self.translated)
        self.text.destroy()
        self.reinit()
        self.text.insert(END,self.translated)
        self.origtext = self.translated
        self.translated = ""
        self.text.pack()

    def key_input(self):
        self.input_type = 0
        choice = None
        dialog = Pmw.CounterDialog(root,
            label_text='Enter the key\n',
            counter_labelpos=N, entryfield_value=self.key,
            counter_datatype='integer',
            entryfield_validate={'validator': 'integer'},
            buttons=('OK', 'Cancel'), defaultbutton='OK',
            title='Key')
        dialog.tkraise()
        result = dialog.activate()
        print ('You clicked on', result, dialog.get())
        self.key = dialog.get()
        self.key_type = 0

    def key_input1(self):
            T = Tk()
            T.title("Input (Ap + B)")
            frame = Frame(T)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            T._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='A',
                format='integer', enter=self.set_A)
            T._crdprt = self.createField(frame, width=16, row=1, col=2,
                label='B',
                format='integer', enter=self.set_B)
            frame.pack(side=TOP, padx=15, pady=15)
            self.key_type = 1
            self.activate()
            Button(T, text = "OK", command = T.destroy).pack()

    def key_input2(self):
            T = Tk()
            T.title("Input (Ap^2 + Bp +C)")
            frame = Frame(T)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            T._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='A',
                format='integer', enter=self.set_A)
            T._crdprt = self.createField(frame, width=16, row=1, col=2,
                label='B',
                format='integer', enter=self.set_B)
            T._hrdprt = self.createField(frame, width=16, row=2, col=2,
                label='C',
                format='integer', enter=self.set_C)
            frame.pack(side=TOP, padx=15, pady=15)
            self.key_type = 2
            self.activate()
            Button(T, text = "OK", command = T.destroy).pack()

    def key_input3(self):
            T = Tk()
            T.title("Input (String)")
            frame = Frame(T)
            Label(frame, text=' ').grid(row=0, column=0,sticky=W)
            Label(frame, text=' ').grid(row=0, column=3,sticky=W)
            T._ipaddr = self.createField(frame, width=16, row=0, col=2,
                label='String',
                format='string', enter=self.set_String)
            frame.pack(side=TOP, padx=15, pady=15)
            self.key_type = 3
            self.activate()
            Button(T, text = "OK", command = T.destroy).pack()

    def set_A(self,event):
        self.A = int(event.widget.get())

    def set_B(self,event):
        self.B = int(event.widget.get())

    def set_C(self,event):
        self.C = int(event.widget.get())

    def set_String(self,event):
        self.String = str(event.widget.get())

    def createField(self, master, label='', text='', width=1,
            format=None, enter=None, row=0, col=0):
            Label(master, text=label).grid(row=row, column=col-1,
                 padx=15, sticky=W)
            id = Entry(master, text=text, width=width, takefocus=1)
            id.bind('<KeyRelease>', format)
            id.bind('<Return>', enter)
            id.grid(row=row, column=col, pady=10, sticky=W)
            return id

    def activate(self):
        #print ('<Return>: value is', event.widget.get())
        print ('A: value is', self.A)
        print ('B: value is', self.B)
        print ('C value is', self.C)
        print ('String: value is', self.String)
        #return event.widget.get()

    def encrypt(self):
        self.crypting(1)

    def decrypt(self):
        self.crypting(0)

    def gk(self):
        print(self.key)

def printl(lang_en):
    L = Label(root, justify = LEFT, text=lang_en)
    L.pack()

def printt(lang):
    print(lang)

def File():
    filemenu = Menu(menubar, tearoff=0)
    filemenu.add_command(label="New", command=obj.newf)
    filemenu.add_command(label="Open", command=obj.openf)
    filemenu.add_command(label="Save", command=obj.savef)
    filemenu.add_command(label="Save as...", command=obj.savefas)
    filemenu.add_command(label="Close", command=obj.closef)
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=root.quit)
    menubar.add_cascade(label="File", menu=filemenu)

def EditEN():
    editmenu = Menu(menubar, tearoff=0)
    editmenu.crypt = Menu(editmenu, tearoff=0)
    editmenu.crypt.add_command(label="Encrypt", command=obj.encrypt)
    editmenu.crypt.add_command(label="Decrypt", command=obj.decrypt)
    editmenu.add_cascade(label="Crypt", menu=editmenu.crypt)

    editmenu.language = Menu(editmenu, tearoff=0)
    editmenu.language.add_checkbutton\
        (label="Українська",  onvalue=False, offvalue=True, variable = obj.var, command = obj.valueChanged)
    editmenu.language.add_checkbutton\
        (label="English",  onvalue=True, offvalue=False, variable = obj.var, command = obj.valueChanged)
    editmenu.add_cascade(label="Language", menu=editmenu.language)

    editmenu.key_select = Menu(editmenu)
    editmenu.key_select.add_command(label="Input key A", command=obj.key_input)
    editmenu.key_select.add_command(label="Input key (Ap + B)", command=obj.key_input1)
    editmenu.key_select.add_command(label="Input key (Ap^2 + Bp + C)", command=obj.key_input2)
    editmenu.key_select.add_command(label="Input key (String)", command=obj.key_input3)
    editmenu.add_cascade(label="Key", menu=editmenu.key_select)
    menubar.add_cascade(label="Edit", menu=editmenu)

def Help():
    helpmenu = Menu(menubar, tearoff=0)
    helpmenu.add_command(label="About...", command=obj.about)
    menubar.add_cascade(label="Help", menu=helpmenu)

###################             MAIN            ######################################

root = Tk()
root.title('Cryptography')
obj = pflile()
#print(type)
menubar = Menu(root)
File()
EditEN()
Help()

root.config(menu=menubar)
root.mainloop()

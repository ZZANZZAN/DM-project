from multiprocessing import Pool
from subprocess import Popen, PIPE, DEVNULL
from random import randint
from math import log10, floor
import os
import sys
import re


# Limitations

BRUTEFORCE = True
RANDOM = True

TIMEOUT          = 15
NATURAL_LOW_1    = 0
NATURAL_HIGH_1   = 1024
NATURAL_HIGH_2   = 64
INT_HIGH         = 10000
NATURAL_MAX_DEG  = 4
RANDOM_COUNT     = 10000


# Naturals templates

templates_natural = [2, 1, 1, 2, 3, 4, 5, 2, 6, 2, 7, 7, 2, 8]

# 1 - single natural
# 2 - two naturals
# 3 - two naturals, first bigger or equal
# 4 - single natural and digit
# 5 - single natural and int
# 6 - two naturals, digit, non-negative result
# 7 - two naturals, first bigger or equal, second non-zero
# 8 - two naturals, at least one non-zero


def main():
    
    global PATH
    PATH = detect_path()            # Executable path
    
    global MODULES
    MODULES = detect_modules()      # Available modules
    
    # Initializing
    
    threads_count = os.cpu_count()
    
    global POOL
    POOL = Pool(threads_count)
    
    # Running
    
    if len(sys.argv) == 1:
        
        # Full testing
        
        test(MODULES)
        
    else:
        
        # Selective testing
        
        modules = argv_modules()
        test(modules)
    
    
    # Terminating
    
    POOL.close()
    


def test(modules):
    
    for module in modules:
        
        index = int(module[1:]) - 1
        
        print(module[0] + '-' + module[1:] + "... ", end = "")
        sys.stdout.flush()
        
        if module[0] == 'N':
            template = str(templates_natural[index])
            globals()["template_" + template](module)
            
        elif module[0] == 'Z':
            pass
            
        elif module[0] == 'Q':
            pass
            
        elif module[0] == 'P':
            pass
        
        else:
            print(" not tested")


def error(module, test, out, ans):
    
    print()
    
    print("   Module: " + module[0] + "-" + module[1:])
    print("   Test:", *test, sep = " ")
    print("   Output: " + out)
    print("   Answer: " + ans)
    
    print()


def check(module, result):
    
    for r in result:
        result = r.get(timeout = TIMEOUT)
        
        if result != True:
            print("failed")
            error(module, *result)
            return
    
    return True


def natural_rand(min = 0):
    
    min_len = len(str(min))
    min_d = floor(log10(min_len)) + 1
    
    length_deg = randint(min_d, NATURAL_MAX_DEG)
    
    length_l = 10 ** (length_deg - 1)
    length_r = 10 ** length_deg - 1
    length = randint(max(length_l, min_len), length_r)
    
    number_l = 10 ** (length - 1)
    number_r = 10 ** length - 1
    number = randint(min, number_r)
    
    return number


def template_1(module):
    
    result = []
    
    # Bruteforce
    
    for i in range(0, NATURAL_HIGH_1):
        result.append(POOL.apply_async(worker, (module, [i])))
    
    # Random
    
    for i in range(RANDOM_COUNT):
        a = natural_rand()
        result.append(POOL.apply_async(worker, (module, [a])))
    
    if check(module, result) == True:
        print("OK")


def template_2(module):
    
    if module == "N10":
        print("not tested")
        return
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j])))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = natural_rand()
            result.append(POOL.apply_async(worker, (module, [a, b])))
    
    if check(module, result) == True:
        print("OK")


def template_3(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(i, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [j, i])))
            
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = natural_rand(a)
            result.append(POOL.apply_async(worker, (module, [b, a])))
    
    if check(module, result) == True:
        print("OK")


def template_4(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_1):
            for j in range(0, 9):
                result.append(POOL.apply_async(worker, (module, [i, j])))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = randint(0, 9)
            result.append(POOL.apply_async(worker, (module, [a, b])))
    
    if check(module, result) == True:
        print("OK")


def template_5(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j])))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = randint(0, INT_HIGH)
            result.append(POOL.apply_async(worker, (module, [a, b])))
    
    if check(module, result) == True:
        print("OK")


def template_6(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, NATURAL_HIGH_2):
                for k in range(0, 9):
                    if N9(i, j, k) >= 0:
                        result.append(POOL.apply_async(worker, (module, [i, j, k])))
    
    if check(module, result) == True:
        print("OK")


def template_7(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(1, NATURAL_HIGH_2):
            for j in range(i, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [j, i])))
    
    if check(module, result) == True:
        print("OK")


def template_8(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, NATURAL_HIGH_2):
                if i or j:
                    result.append(POOL.apply_async(worker, (module, [i, j])))
    
    if check(module, result) == True:
        print("OK")


def worker(module, arguments, cmd = 0):
    
    # Commands
    # 0 - usual work
    # 1 - terminate process
    
    global p
    
    if "p" in globals():
        if cmd == 1:
            p.terminate()
            return
    else:
        if cmd == 0:
            p = Popen([PATH], stdin = PIPE, stdout = PIPE, stderr = DEVNULL)
    
    # Running Python module
    
    ans = globals()[module](*arguments)
    ans = str(ans)
    
    # Running external program
    
    string = module + "\n" + "\n".join(str(n) for n in arguments) + "\n"
    
    p.stdin.write(string.encode())
    p.stdin.flush()
    
    out = p.stdout.readline().decode().strip()
    
    # Comparing results
    
    if ans == out:
        return True
    else:
        return [arguments, out, ans]


def detect_path():
    
    # Searching for executable
    
    if os.name == "posix":
        
        # Linux or UNIX
        
        if os.path.isfile("./dmcp"):
            return "./dmcp"
        elif os.path.isfile("./main"):
            return "./main"
        else:
            print("Error: executable not found. Compile main.c")
            sys.exit(1)
        
    elif os.name == "nt":
        
        # Windows
        
        if os.path.isfile("./dmcp"):
            return "./dmcp.exe"
        elif os.path.isfile("./main"):
            return "./main.exe"
        else:
            print("Error: executable not found. Compile main.c")
            sys.exit(1)
        
    else:
        print("Unknown operating system")
        sys.exit(1)


def detect_modules():
    
    list = Popen([PATH], stdin = PIPE, stderr = PIPE)
    list.stdin.write(b"l\ne\n")
    
    out, err = list.communicate()
    list = err.decode()
    list = list[list.find("List of available modules"):]
    
    regex = r"[N|Z|Q|P]\-\d[ \d]"
    
    modules = re.finditer(regex, list, re.MULTILINE)
    modules = [module[0][0] + module[0][2:].strip() for module in modules]
    
    return modules


def argv_modules():
    
    list = sys.argv[1:]
    result = []
    
    for module in list:
        
        module = module.upper()
        
        if module[1] == '-':
            module = module[0] + module[2:]
        
        if module not in MODULES:
            print(module[0] + '-' + module[1:] + " is not available")
            continue
        
        result.append(module)
        
    return result


# Modules

def N1(a, b):
    if a > b:   return 2
    elif a < b: return 1
    else:       return 0


def N2(a):
    if a == 0: return False
    else: return True


def N3(a):
    return a + 1


def N4(a, b):
    return a + b


def N5(a, b):
    return a - b


def N6(a, b):
    return a * b


def N7(a, k):
    return a * 10 ** k


def N8(a, b):
    return a * b


def N9(a, b, k):
    return a - b * k


def N10(a, b):
    pass


def N11(a, b):
    return a // b


def N12(a, b):
    return a % b


def N13(a, b):
    
    while a and b:
        if a > b:
            a %= b
        else:
            b %= a
    
    return a + b


def N14(a, b):
    return (a * b) // N13(a, b)


main()

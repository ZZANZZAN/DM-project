from multiprocessing import Pool
from subprocess import Popen, PIPE, DEVNULL
from random import randint
from math import log10, floor
import os
import sys
import time
import re


# Limitations

BRUTEFORCE       =  0
RANDOM           =  0

TIMEOUT          =  15

NATURAL_LOW_1    =  0
NATURAL_HIGH_1   =  1024
NATURAL_HIGH_2   =  64
INT_HIGH         =  10000
NATURAL_MAX_DEG  =  3
RANDOM_COUNT     =  1000

INTEGER_LOW_1    = -256
INTEGER_HIGH_1   =  256
INTEGER_LOW_2    =  -64
INTEGER_HIGH_2   =   64


# Naturals templates

templates_N = [2, 1, 1, 2, 3, 4, 5, 2, 6, 7, 7, 7, 8, 8]

# 1 - single natural
# 2 - two naturals
# 3 - two naturals, first bigger or equal
# 4 - single natural and digit
# 5 - single natural and int
# 6 - two naturals, digit, non-negative result
# 7 - two naturals, first bigger or equal, second non-zero
# 8 - two naturals, values at least 1


# Integers templates

templates_Z = [1, 1, 1, 2, 2, 3, 3, 3, 4, 4];

# 1 - single integer
# 2 - single natural
# 3 - two integers
# 4 - two integers, second non-zero


def main():
    
    set_flags()
    
    global PATH
    PATH = detect_path()            # Executable path
    
    global MODULES
    MODULES = detect_modules()      # Available modules
    
    # Initializing
    
    threads_count = os.cpu_count()
    
    global POOL
    POOL = Pool(threads_count)
    
    # Running
    
    global SUCCESS
    SUCCESS = True
    
    if len(sys.argv) == 1:
        
        # Full testing
        
        test(MODULES)
        
    else:
        
        # Selective testing
        
        modules = argv_modules()
        test(modules)
    
    
    # Terminating
    
    POOL.close()
    
    if not SUCCESS:
        sys.exit(1)
    


def test(modules):
    
    for module in modules:
        
        block = module[0]
        index = int(module[1:]) - 1
        
        print(module[0] + '-' + module[1:] + "... ", end = "")
        sys.stdout.flush()
        
        if block == 'Q' or block == 'P':
            print(" not tested")
            continue
            
        template = str(globals()["templates_" + block][index])
        start_time = time.time()
        
        success = globals()["template_" + block + template](module)
        
        if success:
            print("OK", end = "")
        
        duration = round(time.time() - start_time, 2)
        print("    " + str(duration) + "s")


def error(module, test, out, ans):
    
    global SUCCESS
    SUCCESS = False
    
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
    number = randint(max(number_l, min), number_r)
    
    return number


def integer_rand(min = 0):
    
    result = natural_rand(min)
    
    if randint(0, 1) == 1: result *= -1
    
    return result


def template_N1(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(NATURAL_LOW_1, NATURAL_HIGH_1):
            result.append(POOL.apply_async(worker, (module, [i], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            result.append(POOL.apply_async(worker, (module, [a], PATH)))
    
    return check(module, result)


def template_N2(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(NATURAL_LOW_1, NATURAL_HIGH_2):
            for j in range(NATURAL_LOW_1, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = natural_rand()
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)


def template_N3(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(NATURAL_LOW_1, NATURAL_HIGH_2):
            for j in range(i, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [j, i], PATH)))
            
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = natural_rand(a)
            result.append(POOL.apply_async(worker, (module, [b, a], PATH)))
    
    return check(module, result)


def template_N4(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(NATURAL_LOW_1, NATURAL_HIGH_1):
            for j in range(0, 9):
                result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = randint(0, 9)
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)


def template_N5(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            b = randint(0, INT_HIGH)
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)


def template_N6(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_2):
            for j in range(0, 9):
                for k in range(i * j, NATURAL_HIGH_2):
                    result.append(POOL.apply_async(worker, (module, [k, i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            b = natural_rand() // 10
            c = randint(0, 9)
            a = natural_rand(b * c)
            
            result.append(POOL.apply_async(worker, (module, [a, b, c], PATH)))
    
    return check(module, result)


def template_N7(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(1, NATURAL_HIGH_2):
            for j in range(i, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [j, i], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand(1)
            b = natural_rand(a)
            result.append(POOL.apply_async(worker, (module, [b, a], PATH)))
    
    return check(module, result)


def template_N8(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(1, NATURAL_HIGH_2):
            for j in range(1, NATURAL_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand(1)
            b = natural_rand(1)
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)


def template_Z1(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(INTEGER_LOW_1, INTEGER_HIGH_1):
            result.append(POOL.apply_async(worker, (module, [i], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = integer_rand()
            result.append(POOL.apply_async(worker, (module, [a], PATH)))
    
    return check(module, result)


def template_Z2(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(0, NATURAL_HIGH_1):
            result.append(POOL.apply_async(worker, (module, [i], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = natural_rand()
            result.append(POOL.apply_async(worker, (module, [a], PATH)))
    
    return check(module, result)


def template_Z3(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(INTEGER_LOW_2, INTEGER_HIGH_2):
            for j in range(INTEGER_LOW_2, INTEGER_HIGH_2):
                result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = integer_rand()
            b = integer_rand()
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)


def template_Z4(module):
    
    result = []
    
    if BRUTEFORCE:
        for i in range(INTEGER_LOW_2, INTEGER_HIGH_2):
            for j in range(INTEGER_LOW_2, INTEGER_HIGH_2):
                if j != 0:
                    result.append(POOL.apply_async(worker, (module, [i, j], PATH)))
    
    if RANDOM:
        for i in range(RANDOM_COUNT):
            a = integer_rand()
            b = integer_rand(1)
            result.append(POOL.apply_async(worker, (module, [a, b], PATH)))
    
    return check(module, result)
    

def worker(module, arguments, path, cmd = 0):
    
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
            p = Popen([path], stdin = PIPE, stdout = PIPE, stderr = DEVNULL)
    
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


def set_flags():
    
    any_flags = False
    
    global BRUTEFORCE
    global RANDOM
    
    if "-b" in sys.argv:
        sys.argv.remove("-b")
        BRUTEFORCE = 1
        any_flags = True
    
    if "-r" in sys.argv:
        sys.argv.remove("-r")
        RANDOM = 1
        any_flags = True
    
    if not any_flags:
        BRUTEFORCE = 1
        RANDOM = 1

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
        
        if os.path.isfile("./dmcp.exe"):
            return "./dmcp.exe"
        elif os.path.isfile("./main.exe"):
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
    return str(a // b)[0]


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


def Z1(a):
    return abs(a)


def Z2(a):
    if a > 0:   return 2
    elif a < 0: return 1
    else:       return 0


def Z3(a):
    return -a


def Z4(a):
    return a


def Z5(a):
    return abs(a)


def Z6(a, b):
    return a + b


def Z7(a, b):
    return a - b


def Z8(a, b):
    return a * b


def Z9(a, b):
    return a // b


def Z10(a, b):
    return a % b


if __name__ == "__main__":
    main()

#!/bin/python

import subprocess
import os
import sys
import pyperclip

config = {
    "DevkitPPC": None,
    "C++": "g++",
    "strip": "strip"
}


def setup_directory():
    os.chdir(os.path.dirname(os.path.realpath(__file__)))
    os.chdir("..")
    print("cwd = " + os.getcwd())


def detect_devkit_ppc():
    table = {
        "linux": "/opt/devkitPro/devkitPPC",
        "win32": "C:\\devkitPro\\devkitPPC",
    }
    for key in table:
        if sys.platform.startswith(key):
            return table[key]
    return None


def config_devkit_ppc():
    if "DEVKITPPC" in os.environ:
        path = os.environ["DEVKITPPC"]
        print(f"devkitPPC = {path} (from environment)")
        config["DEVKITPPC"] = path
    else:
        detected = detect_devkit_ppc()
        if detected is None:
            print("failed to detect devkitPPC path")
            exit(1)
        print(f"devkitPPC = {detected} (detected)")
        config["DEVKITPPC"] = detected

    if not os.path.exists(config["DEVKITPPC"]):
        print(f"devkitPPC path {config['DEVKITPPC']} does not exist")
        exit(1)

    if not os.path.isdir(config["DEVKITPPC"]):
        print(f"devkitPPC path {config['DEVKITPPC']} is not a directory")
        exit(1)

    os.environ["PATH"] += os.pathsep + os.path.join(config["DEVKITPPC"], "bin")
    config["C++"] = find_executable("powerpc-eabi-g++")
    config["strip"] = find_executable("powerpc-eabi-strip")


def configure():
    config_devkit_ppc()


def find_executable(name):
    if os.path.exists(name):
        return name
    if sys.platform.startswith("win"):
        name += ".exe"
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            exe = os.path.join(path, name)
            if os.path.exists(exe):
                return exe
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            exe = os.path.join(path, name)
            if os.path.exists(exe):
                return exe
    return None


def strip():
    ret = subprocess.call([config["strip"], "-N", "rodata_size", "raw.o"])
    if ret != 0:
        print("failed to strip")
        exit(1)


def symbols():
    nm = find_executable("nm")
    if nm:
        print("----- symbol table -----")
        ret = subprocess.call([nm, "raw.o"])
        if ret != 0:
            print("failed to show symbols")
            exit(1)
    else:
        print("nm not found")


def show_section_headers():
    objdump = find_executable("powerpc-eabi-objdump")
    if objdump:
        print("----- section headers -----")
        ret = subprocess.call([objdump, "--section-headers", "raw.o"])
        if ret != 0:
            print("failed to show section headers")
            exit(1)
    else:
        print("objdump not found")


def compile():
    options = []
    options += ["-nostdlib"]
    options += ["-O2", "-fno-unroll-loops"]
    options += ["-Wall", "-Wno-register"]
    options += ["-fdata-sections", "-ffunction-sections", "-Wl,--gc-sections"]
    options += ["-I", "."]
    options += ["-Wl,-T,link.ld"]
    options += ["-o", "raw.o"]
    options += ["-std=c++2a"]
    options += ["raw.cpp"]

    print(config["C++"] + " " + " ".join(options))

    ret = subprocess.call([config["C++"]] + options)
    if ret != 0:
        print("failed to compile")
        exit(1)


def make_code_bin():
    objcopy = find_executable("powerpc-eabi-objcopy")
    if not objcopy:
        print("powerpc-eabi-objcopy not found")
        exit(1)

    ret = subprocess.call(
        [objcopy, "--only-section=.text", "raw.o", "-O", "binary", "text.bin"])
    if ret != 0:
        print("failed to make text.bin")
        exit(1)

    ret = subprocess.call(
        [objcopy, "--only-section=.data", "raw.o", "-O", "binary", "data.bin"])
    if ret != 0:
        print("failed to make text.bin")
        exit(1)

    with open("code.bin", "wb") as code_bin:
        with open("text.bin", "rb") as text_bin:
            code_bin.write(text_bin.read())
        with open("data.bin", "rb") as data_bin:
            code_bin.write(data_bin.read())


def hex_dump(path, as_str=False):
    ret = ""
    with open(path, "rb") as fp:
        data = fp.read()
        for i in range(0, len(data), 8):
            tok = "{} {}".format(data[i+0: i+4].hex(), data[i+4: i+8].hex())
            if as_str:
                ret += tok+"\n"
            else:
                print(tok)
    return ret


def cleanup():
    os.remove("text.bin")
    os.remove("data.bin")
    os.remove("code.bin")
    os.remove("raw.o")


def dump_data_section():
    print("----- data section -----")
    hex_dump("data.bin")


def dump():
    dump = hex_dump("code.bin", as_str=True)
    pyperclip.copy(dump)


if __name__ == "__main__":
    setup_directory()
    configure()
    compile()
    strip()
    symbols()
    show_section_headers()
    make_code_bin()
    dump_data_section()
    dump()
    cleanup()

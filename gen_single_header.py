#!/usr/bin/env python

from io import BytesIO as StringIO

import os
import sys
import re
import datetime

rootHeaderName = "SmallTest.hpp"

inputPath = "./include/"

singleHeaderName = "SmallTest.h"

includesMatcher = re.compile( r'\s*#include\s*"(.*)"' )

pragmaOnceMatcher = re.compile( r'\s*#pragma\s*once\s*' )

commentRegex = re.compile(r'(^)?[^\S\n]*/(?:\*(.*?)\*/[^\S\n]*|/[^\n]*)($)?',re.DOTALL | re.MULTILINE)

processedHeaders = set([])

def parse(out, filename):
    filePath = os.path.join(inputPath, filename)        
    for line in open(filePath, 'r') :
        m = includesMatcher.match(line)
        if m:
            header = m.group(1)
            if not header in processedHeaders:
                processedHeaders.add(header)
                parse(out, header)
        else:
            out.write(line.rstrip() + "\n")

def writeHeaderComment(out):
    out.write("/*\n")
    out.write(" *  SmallTest - A simplified C++ libreary for unit testing\n" )
    out.write(" *  Generated: {0}".format(datetime.datetime.now()) + "\n")
    out.write(" *  https://github.com/redsquid/SmallTest\n")
    out.write(" */\n")

def commentProcessor(match):
    start,mid,end = match.group(1,2,3)
    if mid is None:
        # single line comment
        return ''
    elif start is not None or end is not None:
        # multi line comment at start or end of a line
        return ''
    elif '\n' in mid:
        # multi line comment with line break
        return '\n'
    else:
        # multi line comment without line break
        return ' '

def removeComments(text):
    return commentRegex.sub(commentProcessor, text)

def removePragmaOnce(text):
    return pragmaOnceMatcher.sub('\n', text)

def createText():
    stream = StringIO() 
    parse(stream, rootHeaderName)
    text = stream.getvalue()
    text = removeComments(text)
    text = removePragmaOnce(text)
    return text

def createFile(text):
    outputPath = os.path.join("./", singleHeaderName)
    out = open(outputPath, 'w')
    out.write("#pragma once\n")
    writeHeaderComment(out)
    out.write(text)
    out.close()

text = createText()
createFile(text)


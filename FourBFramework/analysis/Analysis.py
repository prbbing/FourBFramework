#!/usr/bin/env python
#
import sys,os,string




EvtMax=-1

input = open( 'InputCollection.py', 'r' )
output = open( 'Collection.py', 'w')
for s in input.xreadlines():
      output.write(s.replace('theApp.EvtMax', 'EvtMax'))
input.close()
output.close()


from Collection import * 
# import InputCollection
# get data
InputCollections = dataCollection


# file with data
data_file="data.in"
output = open(data_file, 'w')
for i in InputCollections:
          output.write(i+"\n")
print "created data file="+data_file
output.close()

if EvtMax == -1:
              EvtMax=1000000000

# file with data
data_file="main.ini"
output = open(data_file, 'w')
output.write("events "+str(EvtMax)+"\n")
output.write("debug 0\n")
print "created data file="+data_file
output.close()


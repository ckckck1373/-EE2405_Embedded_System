# Part. 1
#=======================================
# Import module
#  csv -- fileIO operation
import csv
#=======================================
# Part. 2
#=======================================
# Read cwb weather data

cwb_filename = '106011206.csv'
data = []
header = [] # first row in the data(title)
target_name = ['C0A880', 'C0F9A0', 'C0G640', 'C0R190', 'C0X260']
target_data = [[]for j in range(5)] 
output_format = [] 
num_data = 0 # the num of the data (col)

with open(cwb_filename) as csvfile:
   mycsv = csv.DictReader(csvfile)
   header = mycsv.fieldnames
   for row in mycsv:
      data.append(row)
      num_data += 1  

   for i in range(num_data-1):
      if(float(data[i]['WDSD']) >=0):
         if((data[i]['station_id'])=='C0A880'):
            target_data[0].append(float(data[i]['WDSD']))
         elif((data[i]['station_id'])=='C0F9A0'):
            target_data[1].append(float(data[i]['WDSD']))
         elif((data[i]['station_id'])=='C0G640'):
            target_data[2].append(float(data[i]['WDSD']))
         elif((data[i]['station_id'])=='C0R190'):
            target_data[3].append(float(data[i]['WDSD']))
         elif((data[i]['station_id'])=='C0X260'):
            target_data[4].append(float(data[i]['WDSD']))



#=======================================
# Part. 3
#=======================================
# Analyze data depend on your group and store it to target_data like:
# Retrive all data points which station id is "C0X260" as a list.
# target_data = list(filter(lambda item: item['station_id'] == 'C0X260', data))
# Retrive ten data points from the beginning.

# target_data = data[:10]


# calculate the abs of WDSD and remove the useless part (-99 or -999)
for i in range(5):
   if(len(target_data[i])>1):
      max_range = max(target_data[i])- min(target_data[i])
   else: 
      max_range = 'None'

   output_format.append([target_name[i], max_range])


print(output_format)
#=======================================
# Part. 4
#=======================================

# Print result
# print(target_data)

#========================================
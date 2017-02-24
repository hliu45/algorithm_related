import csv
from collections import OrderedDict

def csv_open_file(name):
	file = open(name)
	file_data = csv.reader(file)
	bug_list = list(file_data)
	file.close()
	return bug_list

def developer_vs_id(bug_list):
	diction_who_vs_id={}
	for every in bug_list[1:]:
		if every[3] not in diction_who_vs_id.keys():
			diction_who_vs_id[every[3]]=[every[0]]
		else:
			diction_who_vs_id[every[3]].append(every[0]) 
	del diction_who_vs_id['nobody']
	return diction_who_vs_id

def developer_vs_number_of_id(diction_who_vs_id):
	diction_who_vs_no_id={}
	for key, values in diction_who_vs_id.items():
		diction_who_vs_no_id[key]=len(values)
	return diction_who_vs_no_id


def get_busiest_developer(diction_who_vs_no_id):
	max_bug = 0
	busiest_developer = 'someone'
	for key, values in diction_who_vs_no_id.items():
		if values > max_bug:
			busiest_developer = key
			max_bug = values
	return busiest_developer


def get_easiest_developer(diction_who_vs_no_id):
	min_bug = 100000
	easiest_developer = 'someone'
	for key, values in diction_who_vs_no_id.items():
		if values < min_bug:
			easiest_developer = key
			min_bug = values
	return easiest_developer


def get_sorted_dictionary(diction_who_vs_no_id):
	sort_diction_who_vs_no_id = {}
	sort_developer = sorted(diction_who_vs_no_id, key=diction_who_vs_no_id.get, reverse = True)
	return sort_developer



def get_pie_chart(diction_who_vs_no_id,sort_developer,n):
	import matplotlib.pyplot as plotter
	
	sort_developer = sort_developer[:n]

	data = []
	for developer in sort_developer:
		data.append(diction_who_vs_no_id[developer])

	plotter.pie(data, labels = sort_developer)
	plotter.axis('equal')
	plotter.show()



bug_list = csv_open_file("bugs-2016-10-22.csv")
diction_who_vs_id = developer_vs_id(bug_list)
diction_who_vs_no_id = developer_vs_number_of_id(diction_who_vs_id)
sort_developer = get_sorted_dictionary(diction_who_vs_no_id)
get_pie_chart(diction_who_vs_no_id,sort_developer,20)



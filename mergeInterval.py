def merge(intervals, insert):
	start, end = insert[0], insert[1]

	intervals.append(insert)
	intervals.sort(key = lambda x:x[0])
	stack = []
	hold = False; firstTime = True
	for i, interval in enumerate(intervals):
		if interval[0]>= end:
			if hold or firstTime:
				hold = False
				firstTime = False
				stack.append([start,end])

			stack.append(interval)
		
		elif interval[1] <= start:
			stack.append(interval)

		else:
			start = min(start,interval[0])
			end = max(end,interval[1])
			firstTime = False
			hold = True

			






	print stack

intervals = [[1,2],[3,5],[6,7],[8,10],[14,16]]
insert =[11,12]

intervals1 = [[1,3],[6,9]]
insert1 = [2,5]

print merge(intervals,insert)

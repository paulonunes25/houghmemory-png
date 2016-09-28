from __future__ import division

first = 42
amount = 16
minnoise = 0
maxnoise = 101
threshold = 4

control = [0 for x in range(amount)]
truep = [ [] for x in range(maxnoise)]
falsep = [ [] for x in range(maxnoise)]

for i in range(first,first + amount):
	positionname = 'position_rnd{:04d}.txt'.format(i)
	#print positionname
	p = open(positionname, 'r')
	ctrlset = []
	for line in p:
		tmp = line.split('=')
		ctrlset = ctrlset + [ int(tmp[1]) ]
	control[i - first] = len(ctrlset)

	for j in range(minnoise, maxnoise):
		tp = 0
		fp = 0
		dumpname =  'export_noise00_zzuf-0.{:03d}-dump_rnd{:04d}.dat'.format(j, i)
		#print "   " + dumpname
		f = open(dumpname, 'r')
		for line in f:
			count = line.split(';')
			if int(count[1]) >= threshold:
				if int(count[0]) in ctrlset:
					tp = tp + 1
				else:
					fp = fp + 1
		f.close()	
		truep[j] = truep[j] + [tp]
		falsep[j] = falsep[j] + [fp]

for j in range(minnoise, maxnoise):		
	tp = 0
	fp = 0
	for i in range(0, amount):
		tp = tp + (truep[j][i] / control[i])
		fp = fp + (falsep[j][i] / control[i])
	print str(j) + ";" + str(tp / amount) + ";" + str(fp / amount)


from __future__ import division

first = 26
amount = 16
threshold = 4

for i in range(first,first + amount):
	positionname = 'position_rnd{:04d}.txt'.format(i)
	print positionname
	p = open(positionname, 'r')
	ctrlset = []
	for line in p:
		tmp = line.split('=')
		ctrlset = ctrlset + [ int(tmp[1]) ]

	for j in range(0, 11):
		tp = 0
		fp = 0
		dumpname =  'export_noise00_zzuf-0.{:03d}-dump_rnd{:04d}.dat'.format(j, i)
		print "   " + dumpname
		f = open(dumpname, 'r')
		for line in f:
			count = line.split(';')
			if int(count[1]) >= threshold:
				if int(count[0]) in ctrlset:
					tp = tp + 1
				else:
					fp = fp + 1
		f.close()	
		print '      Control = {:d}, TP = {:d}, FP = {:d}'.format(len(ctrlset), tp, fp)

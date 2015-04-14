import csv



def readFile(file):
    scale = 1
    grid =[]
    with open(file,'rb') as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        i=0
        for row in reader:
            if(i==0):
                scale = float(row[0])
                i+=1
            else:
                grid_row =[]
                for j in range(0,len(row)):
                    grid_row.append(float(row[j])*2)
                grid.append(grid_row)
    return (scale,grid)



if __name__ == "__main__":
    import sys
    file = sys.argv[1]
    readFile(file)
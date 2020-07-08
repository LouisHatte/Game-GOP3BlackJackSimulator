import sys, os
import matplotlib.pyplot as plt

def checkArgs():
    if len(sys.argv) != 2:
        print('Usage: python3 graph.py file_path_name\n', file=sys.stderr)
        exit()

def parseFile():
    path = sys.argv[1]

    if not os.path.isfile(path):
        print('File path {} does not exist. Exiting...'.format(filepath))
        exit()

    lines = []
    with open(path) as fp:
        for line in fp:
           lines.append(line)
    return lines

def getPlots(lines):
    graph = []
    for i in range(1, len(lines)):
        lines[i - 1] = lines[i - 1].replace('\n', '')
        lines[i] = lines[i].replace('\n', '')
        x = [int(lines[i - 1].split(',')[0]), int(lines[i].split(',')[0])]
        y = [int(lines[i - 1].split(',')[1]), int(lines[i].split(',')[1])]
        graph.append([x, y])
    return graph

def drawGraph(graph):
    for i in range(0, len(graph)):
        plt.plot(graph[i][0], graph[i][1])
    plt.show()

if __name__ == '__main__':
    checkArgs()
    lines = parseFile()
    graph = getPlots(lines)
    drawGraph(graph)

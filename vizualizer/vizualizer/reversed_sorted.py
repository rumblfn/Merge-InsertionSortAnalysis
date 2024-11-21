import json
import pandas as pd
import matplotlib.pyplot as plt
import os
import numpy as np

def view(file_name, ax, color):
    calculated_data = {}
    
    with open(f'./assets/{file_name}', 'r') as file:
        calculated_data = json.load(file)
        
    data = {
        'Длина сортируемого массива': [],
        'Время (мс)': []
    }
    
    for key in calculated_data:
        data['Длина сортируемого массива'].append(int(key))
        data['Время (мс)'].append(calculated_data[key])
    
    df = pd.DataFrame(data)

    ax.plot(df['Длина сортируемого массива'], df['Время (мс)'], marker='o', linestyle='-', color=color, label=file_name)

def main():
    contents = ['reversed_merge_sort.json', 'reversed_optimized.json']
    
    # Создаем одну фигуру и один набор осей
    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Используем разные цвета для каждого файла
    colors = plt.cm.jet(np.linspace(0, 1, len(contents)))
    
    for i, item in enumerate(contents):
        view(item, ax, colors[i])
    
    ax.set_title('Сравнение MergeSort и оптимизированного MergeSort (обратно отсортированный массив)')
    ax.set_xlabel('Длина сортируемого массива')
    ax.set_ylabel('Время, затраченное на сортировку (мс)')
    ax.grid(True)
    ax.legend()
    
    plt.savefig('../output/reversed-sorted-array-combined.png')

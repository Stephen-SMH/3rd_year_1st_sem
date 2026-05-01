import tkinter as tk
from tkinter import *

# Symptom-Disease Mapping
disease_data = {
    "Fever, Cough, Fatigue": ["Flu", "Common Cold"],
    "Fever, Headache, Rash": ["Dengue", "Measles"],
    "Abdominal Pain, Vomiting, Diarrhea": ["Food Poisoning", "Gastroenteritis"],
    "Chest Pain, Shortness of Breath": ["Heart Attack", "Asthma"],
}

def diagnose():
    symptoms = symptom_input.get()
    symptoms = symptoms.strip().lower()

    possible_diseases = [
        diseases for sym, diseases in disease_data.items() if symptoms in sym.lower()
    ]

    if possible_diseases:
        output = "\n".join([disease for sublist in possible_diseases for disease in sublist])
        output_label.config(text=f"Possible Diseases:\n{output}")
    else:
        output_label.config(text="No matching diseases found. Please check symptoms!")

# Tkinter UI Setup
root = tk.Tk()
root.title("Disease Diagnosis System")

# Title
title_label = tk.Label(root, text="Disease Diagnosis System", font=("Helvetica", 16, "bold"))
title_label.pack(pady=10)

# Symptom Input Section
symptom_label = tk.Label(root, text="Enter symptoms (comma-separated):", font=("Helvetica", 12))
symptom_label.pack(pady=5)
symptom_input = tk.Entry(root, width=50)
symptom_input.pack(pady=5)

# Diagnose Button
diagnose_button = tk.Button(root, text="Diagnose", command=diagnose, font=("Helvetica", 12), bg="lightblue")
diagnose_button.pack(pady=10)

# Output Section
output_label = tk.Label(root, text="", font=("Helvetica", 12), fg="green", wraplength=400, justify="left")
output_label.pack(pady=10)

# Run Tkinter Event Loop
root.geometry("500x300")
root.mainloop()

SYMPTOMS = {
    "fever": ["flu", "pneumonia", "COVID-19"],
    "cough": ["flu", "pneumonia", "COVID-19"],
    "shortness of breath": ["pneumonia", "COVID-19"],
    "fatigue": ["flu", "pneumonia", "COVID-19"],
    "body aches": ["flu"],
    "sore throat": ["flu", "COVID-19"],
    "headache": ["flu"],
    "loss of smell or taste": ["COVID-19"],
    "diarrhea": ["COVID-19"],
}

TREATMENTS = {
    "flu": ["get rest", "drink fluids", "take over-the-counter medication"],
    "pneumonia": ["antibiotics", "oxygen therapy", "hospitalization"],
    "COVID-19": ["quarantine", "symptomatic treatment", "seek medical attention if symptoms worsen"],
}

def triage(symptoms):
    """Given a set of symptoms, returns a list of potential medical conditions and recommended treatments."""
    conditions = set()
    for symptom in symptoms:
        if symptom in SYMPTOMS:
            conditions.update(SYMPTOMS[symptom])
    treatments = []
    for condition in conditions:
        if condition in TREATMENTS:
            treatments.extend(TREATMENTS[condition])
    return list(conditions), treatments

# Prompt user for symptoms
patient_symptoms = input("What are your symptoms? (separate with commas) ").split(",")

# Remove any leading/trailing white space from symptoms
patient_symptoms = [symptom.strip() for symptom in patient_symptoms]

conditions, treatments = triage(patient_symptoms)
print("Potential conditions:", conditions)
print("Recommended treatments:", treatments)

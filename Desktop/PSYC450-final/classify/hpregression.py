import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer

# Load your data
data = pd.read_csv('dataset_train.csv') 

# Define your numeric and categorical features
numeric_features = ['Arithmancy', 'Astronomy', 'Herbology', 'Defense Against the Dark Arts', 
                    'Divination', 'Muggle Studies', 'Ancient Runes', 'History of Magic',
                    'Transfiguration', 'Potions', 'Care of Magical Creatures', 'Charms', 'Flying']
categorical_features = ['Best Hand']  # Replace with your actual categorical feature names

# Prepare your data (assuming 'Hogwarts House' is your target)
features = data[numeric_features + categorical_features]
target = data['Hogwarts House']

# Split into train and test sets
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.2, random_state=42)


# This will repl

# Create a preprocessing and modeling pipeline
pipeline = Pipeline(steps=[
    ('preprocessor', ColumnTransformer(
        transformers=[
            ('num', StandardScaler(), numeric_features),   # Apply standard scaling to numeric features
            ('cat', OneHotEncoder(), categorical_features) # Apply one-hot encoding to categorical features
        ]
    )),
    ('imputer', SimpleImputer(strategy='mean')),   # Add imputer step to handle NaNs
    ('classifier', LogisticRegression())  # Use a logistic regression classifier
])

# Train the model
pipeline.fit(X_train, y_train)


# Predict the target on the test data
y_pred = pipeline.predict(X_test)

# Evaluate the model
print(f'Accuracy: {accuracy_score(y_test, y_pred)}')
print(classification_report(y_test, y_pred))
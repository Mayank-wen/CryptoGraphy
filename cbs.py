import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
from sklearn.metrics import confusion_matrix

# Read the training data
training = pd.read_csv("Train_data.csv")
print(training.columns)

# Get the shape of the dataset
row, col = training.shape
print(row, col)

# Encode categorical variables using unique values and their indices
for i in range(1, 4):
    L = training.iloc[:, i].unique().tolist()
    print(L)
    for j in range(row):
        training.iloc[j, i] = L.index(training.iloc[j, i])

# Split the data into features and target variable
X_train = training.drop(['class'], axis=1)
Y_train = training['class']
print(Y_train)

# Visualize the class distribution
sns.countplot(x=Y_train)
plt.show()

# Split the data into training and test sets
X_train, X_test, Y_train, Y_test = train_test_split(X_train, Y_train, test_size=0.25, random_state=2)

# Train a Decision Tree classifier
d_tree = DecisionTreeClassifier()
d_tree = d_tree.fit(X_train, Y_train)
plot_tree(d_tree, feature_names=X_train.columns)
plt.show()

# Calculate and print the train and test scores
dt_train, dt_test = d_tree.score(X_train, Y_train), d_tree.score(X_test, Y_test)
print(f'Train Score: {dt_train}')
print(f'Test Score: {dt_test}')

# Plot the decision tree
fig = plt.figure(figsize=(30, 12))
plot_tree(d_tree, filled=True)
plt.show()

# Train a K-Nearest Neighbors classifier
knc = KNeighborsClassifier(n_neighbors=5)
knc.fit(X_train, Y_train)

# Make predictions and calculate accuracy
y_pred = knc.predict(X_test)
score = metrics.accuracy_score(Y_test, y_pred)
print('Accuracy:', score)

# Display the confusion matrix
cfm = confusion_matrix(Y_test, y_pred)
cm_display = metrics.ConfusionMatrixDisplay(confusion_matrix=cfm)
cm_display.plot()
plt.show()

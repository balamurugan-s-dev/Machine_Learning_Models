import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv(r"D:\Models\linear-regression\simple-linear-regression.csv")

plt.scatter(df.x, df.y, label="Actual")
plt.plot(df.x, df.prediction, color="red", label="Predicted")
plt.legend()
plt.show()

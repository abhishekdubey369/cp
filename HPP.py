import sqlite3

# Connect to SQLite database
conn = sqlite3.connect('products.db')
c = conn.cursor()

# Query product with the highest price
c.execute("SELECT * FROM Product ORDER BY price DESC LIMIT 1")
highest_price_product = c.fetchone()

# Close connection
conn.close()

if highest_price_product:
    print("Product with highest price:")
    print(highest_price_product)
else:
    print("No products found in the database.")

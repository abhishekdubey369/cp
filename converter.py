import sqlite3
import json

# Load JSON data
with open('product.json') as f:
    data = json.load(f)

# Connect to SQLite database (you can replace 'products.db' with your database file)
conn = sqlite3.connect('products.db')
c = conn.cursor()

# Create Product table if not exists
c.execute('''CREATE TABLE IF NOT EXISTS Product (
                id INTEGER PRIMARY KEY,
                title TEXT,
                description TEXT,
                price REAL,
                discountPercentage REAL,
                rating REAL,
                stock INTEGER,
                brand TEXT,
                category TEXT,
                thumbnail TEXT,
                images TEXT
            )''')

# Insert data into Product table
for product in data['products']:
    c.execute('''INSERT INTO Product 
                (id, title, description, price, discountPercentage, rating, stock, brand, category, thumbnail, images) 
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''',
                (product['id'], product['title'], product['description'], product['price'],
                 product['discountPercentage'], product['rating'], product['stock'], product['brand'],
                 product['category'], product['thumbnail'], json.dumps(product['images'])))

# Commit changes and close connection
conn.commit()
conn.close()

print("Data inserted successfully!")

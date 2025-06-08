# Last updated: 6/8/2025, 4:52:07 PM
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers[customers['id'].isin(orders['customerId']) == False]

    df = df[['name']].rename(columns={'name': 'Customers'})

    return df
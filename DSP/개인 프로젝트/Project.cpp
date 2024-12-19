#include <iostream>
#include <queue>
#include <string>
#include <memory>
#include <fstream>
#include <climits> 

using namespace std;

struct Material {
    string name;
    int quantity;
    double price;
    double spaceRequired;
};

class Node {
public:
    Material material;
    shared_ptr<Node> next;

    Node(const Material& material) : material(material), next(nullptr) {}
};

class MaterialList {
private:
    shared_ptr<Node> head;

public:
    MaterialList() : head(nullptr) {}

    void addMaterial(const Material& material) {
        auto newNode = make_shared<Node>(material);
        if (!head) {
            head = newNode;
        } 
        else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool modifyMaterial(const string& name, double& totalCost, double& totalSpace) {
        auto current = head;

        while (current) {
            if (current->material.name == name) {
                cout << "������ ������ �Է��ϼ���:\n";

                int oldQuantity = current->material.quantity;
                double oldPrice = current->material.price;
                double oldSpaceRequired = current->material.spaceRequired;

                totalCost -= oldQuantity * oldPrice;
                totalSpace -= oldQuantity * oldSpaceRequired;

                cout << "��� ���� (" << oldQuantity << "): ";
                cin >> current->material.quantity;
                cout << "��� ���� ���� (" << oldPrice << "): ";
                cin >> current->material.price;
                cout << "��� 1���� ����� ���� ���� (" << oldSpaceRequired << "): ";
                cin >> current->material.spaceRequired;

                totalCost += current->material.quantity * current->material.price;
                totalSpace += current->material.quantity * current->material.spaceRequired;

                cout << name << "�� ������ ���������� �����Ǿ����ϴ�.\n";
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool deleteMaterial(const string& name, int deleteQuantity, Material& deletedMaterial) {
        if (!head) return false;

        auto current = head;
        shared_ptr<Node> prev = nullptr;

        while (current && current->material.name != name) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (deleteQuantity > current->material.quantity) {
                deleteQuantity = current->material.quantity;
            }

            deletedMaterial = current->material;
            deletedMaterial.quantity = deleteQuantity;
            current->material.quantity -= deleteQuantity;

            if (current->material.quantity == 0) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
            }
            return true;
        }
        return false;
    }

    void displayMaterials(ostream& out = cout) {
        auto current = head;

        if (!head) {
            out << "���ֵ� ��ᰡ �����ϴ�.\n";
            return;
        }

        out << "=================================\n";
        out << "���� ���ֵ� ��� ���:\n";
        out << "---------------------------------\n";
        out << "����\t\t����\t����(��)\t���� ����(����)\n";
        out << "---------------------------------\n";

        while (current) {
            out << current->material.name << "\t\t"
                << current->material.quantity << "\t"
                << current->material.price << "\t\t"
                << current->material.spaceRequired << "\n";
            current = current->next;
        }
        out << "=================================\n";
    }
};

class POS {
private:
    queue<Material> orderQueue;
    MaterialList orderList;
    double totalCost;
    double totalSpace;
    double refrigeratorCapacity;

public:
    POS() : totalCost(0), totalSpace(0), refrigeratorCapacity(0) {}

    void setRefrigeratorCapacity() {
        cout << "����� �� �뷮�� �Է��ϼ��� (����): ";
        cin >> refrigeratorCapacity;
        cout << "����� �뷮�� " << refrigeratorCapacity << " ������ �����Ǿ����ϴ�.\n";
    }

    void inputMaterial() {
        Material material;
        cout << "������ �Է��ϼ���: ";
        cin >> material.name;
        cout << "��� ������ �Է��ϼ���: ";
        cin >> material.quantity;
        cout << "��� ���� ������ �Է��ϼ���: ";
        cin >> material.price;
        cout << "��� 1���� ����� ���� ������ �Է��ϼ���: ";
        cin >> material.spaceRequired;

        orderQueue.push(material);
        cout << "��ᰡ ���� ��⿭�� �߰��Ǿ����ϴ�.\n";
    }

    void processOrders() {
        while (!orderQueue.empty()) {
            Material material = orderQueue.front();
            double requiredSpace = material.quantity * material.spaceRequired;

            if (totalSpace + requiredSpace > refrigeratorCapacity) {
                cout << "���: ����� �뷮�� �ʰ��Ͽ� " << material.name << " �߰��� �Ұ����մϴ�.\n";
                orderQueue.pop();
                continue;
            }

            orderQueue.pop();
            orderList.addMaterial(material);
            totalCost += material.quantity * material.price;
            totalSpace += requiredSpace;

            cout << material.name << "��(��) ���� ó���Ǿ����ϴ�.\n";
        }
        cout << "��� ���� ��� ��ᰡ ������ �� ���� ���� ��Ͽ� �߰��Ǿ����ϴ�.\n";
    }

    void modifyMaterialInOrderList() {
        string name;
        cin >> name;

        if (orderList.modifyMaterial(name, totalCost, totalSpace)) {
            cout << "��� ������ �����Ǿ����ϴ�.\n";
        } 
        else {
            cout << "�ش� �̸��� ��Ḧ ã�� �� �����ϴ�.\n";
        }
    }

    void deleteMaterialFromOrderList() {
        string name;
        int deleteQuantity;
        cout << "������ ������ �Է��ϼ���: ";
        cin >> name;
        cout << "������ ������ �Է��ϼ���: ";
        cin >> deleteQuantity;

        Material deletedMaterial;
        if (orderList.deleteMaterial(name, deleteQuantity, deletedMaterial)) {
            totalCost -= deletedMaterial.quantity * deletedMaterial.price;
            totalSpace -= deletedMaterial.quantity * deletedMaterial.spaceRequired;
            cout << "��ᰡ ���������� �����Ǿ����ϴ�.\n";
        } 
        else {
            cout << "�ش� �̸��� ��Ḧ ã�� �� �����ϴ�.\n";
        }
    }

    void displayFinalOrder() {
        cout << "\n===== ���� ���� ��� =====\n";
        orderList.displayMaterials();
        cout << "�� ���� ���: " << totalCost << " ��\n";
        cout << "�� ����� ���� ����: " << totalSpace << " / " << refrigeratorCapacity << " ����\n";
    }

    void saveFinalOrderToFile() {
        string fileName;
        cout << "������ ���� �̸��� �Է��ϼ��� (Ȯ���� ����): ";
        cin >> fileName;

        ofstream file(fileName);
        if (!file) {
            cerr << "������ ������ �� �����ϴ�.\n";
            return;
        }

        file << "===== ���� ���� ��� =====\n";
        orderList.displayMaterials(file);
        file << "�� ���� ���: " << totalCost << " ��\n";
        file << "�� ����� ���� ����: " << totalSpace << " / " << refrigeratorCapacity << " ����\n";

        file.close();
        cout << "���� ���� ����� '" << fileName << "' ���Ͽ� ����Ǿ����ϴ�.\n";
    }
};

int main() {
    POS pos;

    while (true) {
        int choice;
        cout << "\nPOS �ý��� �޴�:\n";
        cout << "1. ����� �뷮 ����\n";
        cout << "2. ��� ���� �߰�\n";
        cout << "3. ���� ó��\n";
        cout << "4. ��� ����\n";
        cout << "5. ��� ����\n";
        cout << "6. ���� ���� ��� ����\n";
        cout << "7. ���� ���� ��� ����\n";
        cout << "8. ����\n";
        cout << "����: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n";
            continue;
        }

        switch (choice) {
            case 1:
                pos.setRefrigeratorCapacity();
                break;
            case 2:
                pos.inputMaterial();
                break;
            case 3:
                pos.processOrders();
                break;
            case 4:
                pos.modifyMaterialInOrderList();
                break;
            case 5:
                pos.deleteMaterialFromOrderList();
                break;
            case 6:
                pos.displayFinalOrder();
                break;
            case 7:
                pos.saveFinalOrderToFile();
                break;
            case 8:
                cout << "�ý����� �����մϴ�.\n";
                return 0;
            default:
                cout << "�߸��� �Է��Դϴ�. 1~8 ������ ���ڸ� �Է��ϼ���.\n";
                break;
        }
    }
}
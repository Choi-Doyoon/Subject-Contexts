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
                cout << "수정할 정보를 입력하세요:\n";

                int oldQuantity = current->material.quantity;
                double oldPrice = current->material.price;
                double oldSpaceRequired = current->material.spaceRequired;

                totalCost -= oldQuantity * oldPrice;
                totalSpace -= oldQuantity * oldSpaceRequired;

                cout << "재료 개수 (" << oldQuantity << "): ";
                cin >> current->material.quantity;
                cout << "재료 개당 가격 (" << oldPrice << "): ";
                cin >> current->material.price;
                cout << "재료 1개당 냉장고 차지 공간 (" << oldSpaceRequired << "): ";
                cin >> current->material.spaceRequired;

                totalCost += current->material.quantity * current->material.price;
                totalSpace += current->material.quantity * current->material.spaceRequired;

                cout << name << "의 정보가 성공적으로 수정되었습니다.\n";
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
            out << "발주된 재료가 없습니다.\n";
            return;
        }

        out << "=================================\n";
        out << "현재 발주된 재료 목록:\n";
        out << "---------------------------------\n";
        out << "재료명\t\t개수\t가격(원)\t차지 공간(단위)\n";
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
        cout << "냉장고 총 용량을 입력하세요 (단위): ";
        cin >> refrigeratorCapacity;
        cout << "냉장고 용량이 " << refrigeratorCapacity << " 단위로 설정되었습니다.\n";
    }

    void inputMaterial() {
        Material material;
        cout << "재료명을 입력하세요: ";
        cin >> material.name;
        cout << "재료 개수를 입력하세요: ";
        cin >> material.quantity;
        cout << "재료 개당 가격을 입력하세요: ";
        cin >> material.price;
        cout << "재료 1개당 냉장고 차지 공간을 입력하세요: ";
        cin >> material.spaceRequired;

        orderQueue.push(material);
        cout << "재료가 발주 대기열에 추가되었습니다.\n";
    }

    void processOrders() {
        while (!orderQueue.empty()) {
            Material material = orderQueue.front();
            double requiredSpace = material.quantity * material.spaceRequired;

            if (totalSpace + requiredSpace > refrigeratorCapacity) {
                cout << "경고: 냉장고 용량을 초과하여 " << material.name << " 추가가 불가능합니다.\n";
                orderQueue.pop();
                continue;
            }

            orderQueue.pop();
            orderList.addMaterial(material);
            totalCost += material.quantity * material.price;
            totalSpace += requiredSpace;

            cout << material.name << "이(가) 발주 처리되었습니다.\n";
        }
        cout << "모든 발주 대기 재료가 가능한 한 최종 발주 목록에 추가되었습니다.\n";
    }

    void modifyMaterialInOrderList() {
        string name;
        cin >> name;

        if (orderList.modifyMaterial(name, totalCost, totalSpace)) {
            cout << "재료 정보가 수정되었습니다.\n";
        } 
        else {
            cout << "해당 이름의 재료를 찾을 수 없습니다.\n";
        }
    }

    void deleteMaterialFromOrderList() {
        string name;
        int deleteQuantity;
        cout << "삭제할 재료명을 입력하세요: ";
        cin >> name;
        cout << "삭제할 개수를 입력하세요: ";
        cin >> deleteQuantity;

        Material deletedMaterial;
        if (orderList.deleteMaterial(name, deleteQuantity, deletedMaterial)) {
            totalCost -= deletedMaterial.quantity * deletedMaterial.price;
            totalSpace -= deletedMaterial.quantity * deletedMaterial.spaceRequired;
            cout << "재료가 성공적으로 삭제되었습니다.\n";
        } 
        else {
            cout << "해당 이름의 재료를 찾을 수 없습니다.\n";
        }
    }

    void displayFinalOrder() {
        cout << "\n===== 최종 발주 기록 =====\n";
        orderList.displayMaterials();
        cout << "총 발주 비용: " << totalCost << " 원\n";
        cout << "총 냉장고 차지 공간: " << totalSpace << " / " << refrigeratorCapacity << " 단위\n";
    }

    void saveFinalOrderToFile() {
        string fileName;
        cout << "저장할 파일 이름을 입력하세요 (확장자 포함): ";
        cin >> fileName;

        ofstream file(fileName);
        if (!file) {
            cerr << "파일을 생성할 수 없습니다.\n";
            return;
        }

        file << "===== 최종 발주 기록 =====\n";
        orderList.displayMaterials(file);
        file << "총 발주 비용: " << totalCost << " 원\n";
        file << "총 냉장고 차지 공간: " << totalSpace << " / " << refrigeratorCapacity << " 단위\n";

        file.close();
        cout << "최종 발주 기록이 '" << fileName << "' 파일에 저장되었습니다.\n";
    }
};

int main() {
    POS pos;

    while (true) {
        int choice;
        cout << "\nPOS 시스템 메뉴:\n";
        cout << "1. 냉장고 용량 설정\n";
        cout << "2. 재료 발주 추가\n";
        cout << "3. 발주 처리\n";
        cout << "4. 재료 수정\n";
        cout << "5. 재료 삭제\n";
        cout << "6. 최종 발주 기록 보기\n";
        cout << "7. 최종 발주 기록 저장\n";
        cout << "8. 종료\n";
        cout << "선택: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "잘못된 입력입니다. 숫자를 입력하세요.\n";
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
                cout << "시스템을 종료합니다.\n";
                return 0;
            default:
                cout << "잘못된 입력입니다. 1~8 사이의 숫자를 입력하세요.\n";
                break;
        }
    }
}
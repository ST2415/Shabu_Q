// กำหนดที่อยู่ของ C++ Server
const API_URL = 'http://localhost:8080';

// ==========================================
// 1. ฟังก์ชันดึงข้อมูลจาก C++ มาอัปเดตหน้าจอ
// ==========================================
async function updateDashboard() {
    try {
        let response = await fetch(API_URL + '/api/get-queue');
        let db = await response.json(); // <--- ตัวแปร db ถูกสร้างใหม่ตรงนี้จากข้อมูลที่ C++ ส่งมา
        
        // --- ส่วนอัปเดตตัวเลขคิว ---
        if (document.getElementById('wait-single')) {
            document.getElementById('wait-single').innerText = db.waitSingle;
            document.getElementById('next-single').innerText = db.nextSingle;
            document.getElementById('wait-family').innerText = db.waitFamily;
            document.getElementById('next-family').innerText = db.nextFamily;
        }

        // --- ส่วนวาดโต๊ะ Single ---
        const singleContainer = document.getElementById('single-tables-container');
        if (singleContainer) {
            singleContainer.innerHTML = '';
            db.tableSingle.forEach((qNum, index) => {
                const div = document.createElement('div');
                div.className = `table-box ${qNum > 0 ? 'occupied' : ''}`;
                div.innerHTML = `T${index + 1}<span>${qNum > 0 ? 'Q: '+qNum : 'Empty'}</span>`;
                div.onclick = () => checkoutTable('Single', index);
                singleContainer.appendChild(div);
            });
        }

        // --- ส่วนวาดโต๊ะ Family ---
        const familyContainer = document.getElementById('family-tables-container');
        if (familyContainer) {
            familyContainer.innerHTML = '';
            db.tableFamily.forEach((qNum, index) => {
                const div = document.createElement('div');
                div.className = `table-box ${qNum > 0 ? 'occupied' : ''}`;
                div.innerHTML = `F${index + 1}<span>${qNum > 0 ? 'Q: '+qNum : 'Empty'}</span>`;
                div.onclick = () => checkoutTable('Family', index);
                familyContainer.appendChild(div);
            });
        }
    } catch (error) {
        console.error("กำลังรอการเชื่อมต่อกับ C++ Server...");
    }
}

// ==========================================
// 2. ฟังก์ชันฝั่งลูกค้า (ส่งคำสั่งไปขอคิวจาก C++)
// ==========================================
async function getQueue() {
    const type = document.getElementById('table-type').value;
    const set = document.getElementById('shabu-set').value;

    try {
        let response = await fetch(API_URL + '/api/add-queue', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ tableType: type, shabuSet: set })
        });
        
        let result = await response.json();

        document.getElementById('ticket-number').innerText = result.myQ;
        document.getElementById('ticket-info').innerHTML = `Table: <b>${type}</b> | Set: <b>${set}</b><br>There are ${result.waiting} queue(s) before you.`;
        document.getElementById('ticket-result').classList.remove('hidden');

    } catch (error) {
        alert("เซิร์ฟเวอร์ C++ ยังไม่เปิดทำงาน! โปรดรัน .\\server.exe ก่อนครับ");
    }
}

// ==========================================
// 3. ฟังก์ชันฝั่งพนักงาน (ส่งคำสั่งเรียกคิวและเช็คบิลไปให้ C++)
// ==========================================
async function callQueue(type) {
    try {
        let response = await fetch(API_URL + '/api/call-queue', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ tableType: type })
        });
        
        let result = await response.json();
        
        // ดักจับคำจาก C++ แล้วโชว์แจ้งเตือนภาษาไทย
        if(result.message.includes("full")) {
            alert("โต๊ะ " + type + " เต็มแล้ว!");
        } else if (result.message.includes("No customer")) {
            alert("ไม่มีลูกค้าในคิว!");
        }
        
        updateDashboard();
    } catch (error) {
        console.error(error); // เพิ่มบรรทัดนี้เพื่อแอบดู Error ลึกๆ ใน F12 ได้
        alert("เกิดข้อผิดพลาดในการเรียกคิว!");
    }
}

async function checkoutTable(type, index) {
    if (confirm(`Checkout ${type} Table ${index + 1}?`)) {
        try {
            let response = await fetch(API_URL + '/api/checkout', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ tableType: type, tableIndex: index })
            });
            
            let result = await response.json();
            
            // ดักจับคำว่า empty จาก C++
            if(result.message.includes("empty")) {
                alert("โต๊ะนี้ว่าง ไม่มีลูกค้าอยู่!");
            }
            
            updateDashboard();
        } catch (error) {
            console.error(error);
            alert("เกิดข้อผิดพลาดในการเช็คบิล!");
        }
    }
}

// ==========================================
// ระบบรันอัตโนมัติเมื่อเปิดหน้าเว็บ
// ==========================================
window.onload = () => {
    // ถ้าหน้านี้มีกล่องใส่โต๊ะ (แปลว่าเป็นหน้า Employee) ให้ดึงข้อมูลมาวาดโต๊ะเลย
    if (document.getElementById('single-tables-container')) {
        updateDashboard();
        
        // ให้มันแอบดึงข้อมูลจาก C++ มาอัปเดตหน้าจอทุกๆ 2 วินาที (Real-time)
        setInterval(updateDashboard, 2000); 
    }
};